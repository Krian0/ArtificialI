#include "Player.h"
#include "KeyboardController.h"

Player::Player(Agent* Target, aie::Texture* Hit_Sprite)
{
	m_brain.target	= Target;
	m_brain.behaviours.push_back(new KeyboardController);
	m_velocityLimit = 120;

	m_frame.m_sprite	= new aie::Texture("./textures/ball_2.png");
	m_frame.m_hitSprite	= Hit_Sprite;

	m_flickerCounter	= 0;
	m_flickerTime		= 0;
	m_firstRound		= false;
}

Player::~Player()
{
	delete m_frame.m_sprite;

	m_brain.behaviours.~vector();
}


void Player::Update(float DeltaTime)
{
	//Sense
	//Think
	//Act
	for (auto iter = m_brain.behaviours.begin(); iter != m_brain.behaviours.end(); iter++)
		(*iter)->Update(this);
	//~

	//Move
	m_frame.velocity += m_frame.force * DeltaTime;

	if (m_frame.velocity.magnitude() > m_velocityLimit)
	{
		m_frame.velocity.normaliseDirect();
		m_frame.velocity *= m_velocityLimit;
	}

	Vector2 NewPos = m_frame.collider.GetMidPos() += m_frame.velocity * DeltaTime;
	m_frame.collider.SetMidPos(NewPos);
	//~
	
	//Count how much time has passed if counter is above 0 (player has been hit), skips once each time the player has been hit
	if (m_flickerCounter > 0 && m_firstRound == false)
		m_flickerTime + DeltaTime;
	//~
}

void Player::Draw(aie::Renderer2D* renderer)
{
	Vector2 Pos = m_frame.collider.GetMidPos;

	//Draw sprite: if player has been hit, the sprite drawn will switch between m_hitSprite and m_sprite every 0.4 seconds 5 times
	if (m_flickerCounter == 1 || m_flickerCounter == 3 || m_flickerCounter == 5)
	{
		renderer->drawSprite(m_frame.m_hitSprite, Pos.x, Pos.y, 100, 100);

		if (m_firstRound == true)
			m_firstRound = false;
	}
	
	else
		renderer->drawSprite(m_frame.m_sprite, Pos.x, Pos.y, 100, 100);
	//~


	//If 0.4 or more seconds has passed since the last sprite switch, and there are still switches left, switch sprites
	if (m_flickerTime >= 0.4 && m_flickerCounter > 0)
	{
		m_flickerTime = 0;
		m_flickerCounter--;
	}
	//~
}