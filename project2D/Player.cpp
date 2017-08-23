#include "Player.h"

Player::Player(Agent* Enemy_Target)
{
	m_brain.target = Enemy_Target;
	m_velocityLimit = 120;
}

Player::~Player()
{
	delete m_brain.stateMachine;
}


void Player::Update(float DeltaTime)
{
	//Sense
	//Think
	//Act
	for (auto iter = m_brain.behaviours.begin(); iter != m_brain.behaviours.end(); iter++)
		(*iter)->Update(this);

	//Move
	m_frame.velocity += m_frame.force * DeltaTime;

	if (m_frame.velocity.magnitude() > m_velocityLimit)
	{
		m_frame.velocity.normaliseDirect();
		m_frame.velocity *= m_velocityLimit;
	}

	m_frame.position += m_frame.velocity * DeltaTime;
}

void Player::Draw(aie::Renderer2D* renderer)
{

}