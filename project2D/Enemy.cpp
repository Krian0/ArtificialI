#include "Enemy.h"
#include "Vector2.h"
#include "BoxObject.h"
#include "StateEnum.h"
#include "StateMachine.h"
#include "BehaviourEnum.h"
#include "SteeringBehaviour.h"

Enemy::Enemy(Agent* Target, Texture* Sprite, Texture* Hit_Sprite, Vector2 Position, Vector2 WindowSize, AStarGraph* Graph)
{
	m_isPlayer = false;
	m_windowSize = WindowSize;

	m_targets.push_back(Target);
	m_behaviours[BehaviourE::STEERING] = new SteeringBehaviour;
	m_stateMachine = new StateMachine(this, StateE::WANDER);

	m_sprite = Sprite;
	m_hitSprite = Hit_Sprite;
	m_position = Position;
	m_radius = 10;

	m_flickerCounter = 0;
	m_flickerTime = 0;
	m_firstRound = false;

	m_sightRange = 250;
	m_attackRange = 30;
	m_velocityLimit = 480;

	m_pathfinding = Graph;
	m_pathfindingMode = false;
}

Enemy::~Enemy()
{
	delete m_stateMachine;
	m_behaviours.clear();
}

void Enemy::Update(float DeltaTime)
{
	//Update StateMachine and Behaviours
	m_stateMachine->Update(this, DeltaTime);

	for (unsigned int i = 0; i < m_behaviours.size(); i++)
		m_behaviours.at(BehaviourE(i))->Update(this, DeltaTime);

	//Move
	m_velocity += m_force * DeltaTime;

	if (m_velocity.magnitude() > m_velocityLimit)
	{
		m_velocity.normaliseDirect();
		m_velocity *= (float)m_velocityLimit;
	}

	m_position += m_velocity * DeltaTime;

	//Limit Enemy movement to window size
	OnCollide(Vector2(m_radius, m_radius), Vector2(m_windowSize.x - m_radius, m_windowSize.y - m_radius));

	//Move Agent out of other Agents and Objects, reverse velocity and degrade velocity on collision
	if (IsColliding(m_targets[0]) == true)
		OnCollide(m_targets[0]->GetPos());

	for (auto FR : m_friends)
		if (IsColliding(FR) == true)
			OnCollide(FR->GetPos());

	for (auto OB : m_objects)
		if (OB->IsColliding(this) == true)
			OnCollide(OB);


	//Count how much time has passed if counter is above 0 (Enemy has been hit), skips once each time the Enemy has been hit
	if (m_flickerCounter > 0 && m_firstRound == false)
		m_flickerTime += DeltaTime;
}

void Enemy::Draw(Renderer2D* renderer)
{
	//Draw sprite: if Enemy has been hit, the sprite drawn will switch between m_hitSprite and m_sprite every 0.4 seconds 5 times
	if (m_flickerCounter == 1 || m_flickerCounter == 3 || m_flickerCounter == 5)
	{
		renderer->drawSprite(m_hitSprite, m_position.x, m_position.y, m_radius * 2, m_radius * 2);

		if (m_firstRound == true)
			m_firstRound = false;
	}

	else
		renderer->drawSprite(m_sprite, m_position.x, m_position.y, m_radius * 2, m_radius * 2);

	//Draw circle representing the Node the Enemy is seeking towards
	renderer->setRenderColour( 1, 1, 0);
	renderer->drawCircle(m_currentlySeeking.x, m_currentlySeeking.y, 10);
	renderer->setRenderColour(1, 1, 1, 1);


	//If 0.1 or more seconds has passed since the last sprite switch, and there are still switches left, switch sprites
	if (m_flickerTime >= 0.1 && m_flickerCounter > 0)
	{
		m_flickerTime = 0;
		m_flickerCounter--;
	}
}