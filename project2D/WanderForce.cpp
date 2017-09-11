#include "WanderForce.h"

WanderForce::WanderForce()
{
	m_wanderRadius = 40;
	m_wanderDistance = 60;
	m_wanderJitter = 5;
	m_previousTarget = Vector2(rand() % 100 - 50, rand() % 100 - 50);
	m_previousTarget = m_previousTarget.normalise() * m_wanderRadius;
}

WanderForce::~WanderForce()
{
}

Vector2 WanderForce::GetForce(Agent* An_Agent)
{
	srand((unsigned int)time(NULL));

	Vector2 jitter = Vector2(rand() % 100 - 50, rand() % 100 - 50);
	jitter = jitter.normalise() * m_wanderJitter;

	m_previousTarget += jitter;
	m_previousTarget = m_previousTarget.normalise() * m_wanderRadius;

	
	Vector2 AgentVelocity = An_Agent->GetCurrentVelocity();
	
	if (AgentVelocity.magnitude() == 0)
		AgentVelocity = Vector2(0, 1);
	
	Vector2 AgentPos = An_Agent->GetPos();
	Vector2 TargetPos = AgentPos + AgentVelocity.normalise() * m_wanderDistance + m_previousTarget;
	Vector2 Force = ((TargetPos - AgentPos).normalise() * An_Agent->m_velocityLimit);


	return Force;
}