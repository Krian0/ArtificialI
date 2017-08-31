#include "Player.h"

Player::Player(Agent* Target, Texture* Hit_Sprite, Vector2 Position, float Radius)
{
	m_target	= Target;
	m_behaviours.push_back(new KeyboardController);
	m_velocityLimit = 800;

	m_sprite	= new Texture("./textures/ball_2.png");
	m_hitSprite	= Hit_Sprite;
	m_collider.SetMidPos(Position);
	m_collider.SetRadius(Radius);

	m_flickerCounter	= 0;
	m_flickerTime		= 0;
	m_firstRound		= false;
}

Player::~Player()
{
	delete m_sprite;

	m_behaviours.~vector();
}


void Player::Update(float DeltaTime)
{
	//Sense
	//Think
	//Act
	for (auto iter = m_behaviours.begin(); iter != m_behaviours.end(); iter++)
		(*iter)->Update(this);
	//~

	//Move
	m_velocity += m_force * DeltaTime;

	//Slow the Player's movement in a particular direction if the corresponding direction key is not being pressed
	if (m_force.x == 0)
	{
		if (m_velocity.x > 0)
			m_velocity.x -= 0.1;
		if (m_velocity.x < 0)
			m_velocity.x += 0.1;
	}

	if (m_force.y == 0)
	{
		if (m_velocity.y > 0)
			m_velocity.y -= 0.1;
		if (m_velocity.y < 0)
			m_velocity.y += 0.1;
	}
	//~

	if (m_velocity.magnitude() > m_velocityLimit)
	{
		m_velocity.normaliseDirect();
		m_velocity *= m_velocityLimit;
	}

	Vector2 NewPos = (m_collider.GetMidPos() += (m_velocity * DeltaTime));

	//Limit Player movement to window size
	float R = (m_collider.GetRadius() / 2);

	if (NewPos.y > 720 - R)
	{
		NewPos.y -= 6;
		m_velocity.y = 0;
	}
	if (NewPos.y < 0 + R)
	{
		NewPos.y += 6;
		m_velocity.y = 0;
	}
	
	if (NewPos.x > 1280 - R)
	{
		NewPos.x -= 6;
		m_velocity.x = 0;
	}
	if (NewPos.x < 0 + R)
	{
		NewPos.x += 6;
		m_velocity.x = 0;
	}
	//~

	m_collider.SetMidPos(NewPos);
	//~
	
	
	//Count how much time has passed if counter is above 0 (Player has been hit), skips once each time the Player has been hit
	if (m_flickerCounter > 0 && m_firstRound == false)
		m_flickerTime += DeltaTime;
	//~
}

void Player::Draw(Renderer2D* renderer)
{
	Vector2 Pos = m_collider.GetMidPos();

	//Draw sprite: if Player has been hit, the sprite drawn will switch between m_hitSprite and m_sprite every 0.4 seconds 5 times
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