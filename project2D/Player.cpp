#include "Player.h"

Player::Player(vector<IBehaviour*> Behaviours, Texture* Hit_Sprite, Vector2 Position)
{
	m_target	= NULL;
	m_velocityLimit = 800;
	m_behaviours.push_back(Behaviours[(int)BehaviourEnum::STEERING]);
	m_behaviours.push_back(Behaviours[(int)BehaviourEnum::KEYBOARD]);


	m_sprite	= new Texture("./textures/ball_2.png");
	m_hitSprite	= Hit_Sprite;
	m_position = Position;
	m_radius = 22;

	m_flickerCounter	= 0;
	m_flickerTime		= 0;
	m_firstRound		= false;

	m_sightRange = 250;
	m_attackRange = 40;
	m_velocityLimit = 500;
}

Player::~Player()
{
	delete m_sprite;
}


void Player::Update(float DeltaTime)
{
	//Sense
	//Think
	//Act
	for (auto iter = m_behaviours.begin(); iter != m_behaviours.end(); iter++)
		(*iter)->Update(this, DeltaTime);
	//~

	//Move
	m_velocity += m_force * DeltaTime;

	if (m_velocity.magnitude() > m_velocityLimit)
	{
		m_velocity.normaliseDirect();
		m_velocity *= (float)m_velocityLimit;
	}

	m_position += (m_velocity * DeltaTime);

	//Limit Player movement to window size
	float R = (m_radius / 2);

	if (m_position.y > 720 - R)
	{
		m_position.y -= 6;
		m_velocity.y = -m_velocity.y;
	}
	if (m_position.y < 0 + R)
	{
		m_position.y += 6;
		m_velocity.y = -m_velocity.y;
	}
	
	if (m_position.x > 1280 - R)
	{
		m_position.x -= 6;
		m_velocity.x = -m_velocity.x;
	}
	if (m_position.x < 0 + R)
	{
		m_position.x += 6;
		m_velocity.x = -m_velocity.x;
	}
	//~

	//Check for any collisions and bounce
	for (signed int i = 0; i < m_enemyList.size(); i++)
	{
		if (Collision(m_enemyList[i]) == true)
			m_velocity = Vector2(-m_velocity.x, -m_velocity.y);
	}
	//~~
	
	
	//Count how much time has passed if counter is above 0 (Player has been hit), skips once each time the Player has been hit
	if (m_flickerCounter > 0 && m_firstRound == false)
		m_flickerTime += DeltaTime;
	//~
}

void Player::Draw(Renderer2D* renderer)
{
	//Draw sprite: if Player has been hit, the sprite drawn will switch between m_hitSprite and m_sprite every 0.4 seconds 5 times
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


void Player::FindClosestEnemy(vector<Agent*> Enemies)
{
	float PreviousDistance = 999999;

	for (signed int i = 0; i < Enemies.size(); i++)
	{
		Vector2 Pos = Enemies[i]->GetPos() - m_position;
		float CurrentDistance = Pos.dot(Pos);

		if (CurrentDistance < PreviousDistance)
		{
			m_target = Enemies[i];
			PreviousDistance = CurrentDistance;
		}
	}

	m_enemyList = Enemies;
}