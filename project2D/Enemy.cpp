#include "Enemy.h"

Enemy::Enemy(vector<State*> Available_States, map<StateEnum, int> State_Map, Agent* The_Player)
{
	m_brain.stateMachine = new StateMachine(Available_States, State_Map);
	m_brain.target = The_Player;

	m_brain.stateMachine->ChangeState(this, WANDER);
}

Enemy::~Enemy()
{
	delete m_brain.stateMachine;
}

void Enemy::Update(float DeltaTime)
{
	m_brain.stateMachine->Update(this);

	m_frame.velocity += m_frame.force * DeltaTime;

	//Move
	if (m_frame.velocity.magnitude() > m_velocityLimit)
	{
		m_frame.velocity.normaliseDirect();
		m_frame.velocity *= m_velocityLimit;
	}

	m_frame.position += m_frame.velocity * DeltaTime;
}

void Enemy::Draw(aie::Renderer2D* renderer)
{

}