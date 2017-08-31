#include "Enemy.h"

Enemy::Enemy(Agent* Target, vector<State*> States, map<StateEnum, int> State_Map, Texture* Sprite, Texture* Hit_Sprite, Vector2 Position, float Radius)
{
	m_stateMachine = new StateMachine(States, State_Map);
	m_target = Target;

	m_stateMachine->ChangeState(this, WANDER);

	m_sprite = Sprite;
	m_hitSprite = Hit_Sprite;
	m_collider.SetMidPos(Position);
	m_collider.SetRadius(Radius);

	m_flickerCounter = 0;
	m_flickerTime = 0;
	m_firstRound = false;
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

	Vector2 NewPos = m_collider.GetMidPos() += m_velocity * DeltaTime;
	m_collider.SetMidPos(NewPos);
	//~


	//Count how much time has passed if counter is above 0 (Enemy has been hit), skips once each time the Enemy has been hit
	if (m_flickerCounter > 0 && m_firstRound == false)
		m_flickerTime += DeltaTime;
	//~
}

void Enemy::Draw(Renderer2D* renderer)
{
	Vector2 Pos = m_collider.GetMidPos();

	//Draw sprite: if Enemy has been hit, the sprite drawn will switch between m_hitSprite and m_sprite every 0.4 seconds 5 times
	if (m_flickerCounter == 1 || m_flickerCounter == 3 || m_flickerCounter == 5)
	{
		renderer->drawSprite(m_hitSprite, Pos.x, Pos.y, 44, 44);

		if (m_firstRound == true)
			m_firstRound = false;
	}

	else
		renderer->drawSprite(m_sprite, Pos.x, Pos.y, 44, 44);
	//~


	//If 0.4 or more seconds has passed since the last sprite switch, and there are still switches left, switch sprites
	if (m_flickerTime >= 0.4 && m_flickerCounter > 0)
	{
		m_flickerTime = 0;
		m_flickerCounter--;
	}
	//~
}