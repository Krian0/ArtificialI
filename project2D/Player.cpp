#include "Player.h"

Player::Player(Texture* Hit_Sprite, Vector2 Position)
{
	m_isPlayer = true;

	m_velocityLimit = 800;
	m_behaviours[BehaviourE::STEERING] = new SteeringBehaviour;
	m_stateMachine = new StateMachine(this, StateE::ATTACK);


	m_sprite	= new Texture("./textures/ball_2.png");
	m_hitSprite	= Hit_Sprite;
	m_position = Position;
	m_radius = 16;

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
	delete m_stateMachine;
	m_behaviours.clear();
}


void Player::Update(float DeltaTime)
{
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

	m_position += (m_velocity * DeltaTime);

	//Limit Player movement to window size
	float R = (m_radius / 2);
	float D = 1.7f;
	int PushDistance = 4;

	if (m_position.y > 720 - R)
	{
		m_position.y -= PushDistance;
		m_velocity.y = -m_velocity.y / D;
	}
	if (m_position.y < 0 + R)
	{
		m_position.y += PushDistance;
		m_velocity.y = -m_velocity.y / D;
	}
	
	if (m_position.x > 1280 - R)
	{
		m_position.x -= PushDistance;
		m_velocity.x = -m_velocity.x / D;
	}
	if (m_position.x < 0 + R)
	{
		m_position.x += PushDistance;
		m_velocity.x = -m_velocity.x / D;
	}
	//~

	//Check for any collisions and bounce
	for (unsigned int i = 0; i < m_targets.size(); i++)
	{
		if (IsColliding(m_targets[i]) == true)
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
		renderer->drawSprite(m_hitSprite, m_position.x, m_position.y, m_radius * 2, m_radius * 2);

		if (m_firstRound == true)
			m_firstRound = false;
	}


	else
		renderer->drawSprite(m_sprite, m_position.x, m_position.y, m_radius * 2, m_radius * 2);
	//~


	//If 0.1 or more seconds has passed since the last sprite switch, and there are still switches left, switch sprites
	if (m_flickerTime >= 0.1 && m_flickerCounter > 0)
	{
		m_flickerTime = 0;
		m_flickerCounter--;
	}
	//~
}