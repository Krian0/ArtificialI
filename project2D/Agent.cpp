#include "Agent.h"

void Agent::AddForce(Vector2 force)
{
	m_force = force;
}

void Agent::OnHit()
{
	m_flickerCounter = 5;
	m_flickerTime = 0;

	m_firstRound = true;
}


//Get Functions
Vector2 Agent::GetPos()
{
	return m_collider.GetMidPos();
}

Vector2 Agent::GetTargetPos()
{
	return m_target->GetPos();
}

Agent* Agent::GetTarget()
{
	return m_target;
}

Circle Agent::GetCollider()
{
	return m_collider;
}