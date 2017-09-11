#include "Enemy.h"

Enemy::Enemy(Agent* Target, vector<State*> States, map<StateEnum, int> State_Map, Texture* Sprite, Texture* Hit_Sprite, Vector2 Position, float Radius)
{
	m_stateMachine = new StateMachine(States, State_Map, this);
	m_target = Target;

	m_stateMachine->ChangeState(this, WANDER);

	m_sprite = Sprite;
	m_hitSprite = Hit_Sprite;
	m_position = Position;
	m_radius = Radius;

	m_flickerCounter = 0;
	m_flickerTime = 0;
	m_firstRound = false;

	m_sightRange = 250;
	m_attackRange = 50;
	m_velocityLimit = 480;
}

Enemy::~Enemy()
{
	delete m_stateMachine;
}

void Enemy::Update(float DeltaTime)
{
	m_stateMachine->Update(this, DeltaTime);

	//Move
	m_velocity += m_force * DeltaTime;

	if (m_velocity.magnitude() > m_velocityLimit)
	{
		m_velocity.normaliseDirect();
		m_velocity *= (float)m_velocityLimit;
	}

	m_position += m_velocity * DeltaTime;

	//Limit Enemy movement to window size
	float R = (m_radius / 2);
	float PushDistance = 14;

	if (m_position.y > 720 - R)
	{
		m_position.y -= PushDistance;
		m_velocity = Vector2(-m_velocity.x, -m_velocity.y);
		m_hitWall = true;
	}
	if (m_position.y < 0 + R)
	{
		m_position.y += PushDistance;
		m_velocity = Vector2(-m_velocity.x, -m_velocity.y);
		m_hitWall = true;
	}

	if (m_position.x > 1280 - R)
	{
		m_position.x -= PushDistance;
		m_velocity = Vector2(-m_velocity.x, -m_velocity.y);
		m_hitWall = true;
	}
	if (m_position.x < 0 + R)
	{
		m_position.x += PushDistance;
		m_velocity = Vector2(-m_velocity.x, -m_velocity.y);
		m_hitWall = true;
	}
	//~

	//Check for any collisions and bounce
		if (Collision(m_target) == true)
			m_velocity = Vector2(-m_velocity.x, -m_velocity.y);
	//~~


	//Count how much time has passed if counter is above 0 (Enemy has been hit), skips once each time the Enemy has been hit
	if (m_flickerCounter > 0 && m_firstRound == false)
		m_flickerTime += DeltaTime;
	//~
}

void Enemy::Draw(Renderer2D* renderer)
{
	//Draw sprite: if Enemy has been hit, the sprite drawn will switch between m_hitSprite and m_sprite every 0.4 seconds 5 times
	if (m_flickerCounter == 1 || m_flickerCounter == 3 || m_flickerCounter == 5)
	{
		renderer->drawSprite(m_hitSprite, m_position.x, m_position.y);

		if (m_firstRound == true)
			m_firstRound = false;
	}

	else
		renderer->drawSprite(m_sprite, m_position.x, m_position.y);
	//~


	//If 0.1 or more seconds has passed since the last sprite switch, and there are still switches left, switch sprites
	if (m_flickerTime >= 0.1 && m_flickerCounter > 0)
	{
		m_flickerTime = 0;
		m_flickerCounter--;
	}
	//~
}