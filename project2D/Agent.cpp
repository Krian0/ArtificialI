#include "Agent.h"

void Agent::AddForce(Vector2 force)
{
	m_frame.force = force;
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
	return m_frame.collider.GetMidPos();
}

Vector2 Agent::GetTargetPos()
{
	return m_brain.target->GetPos();
}

Agent* Agent::GetTarget()
{
	return m_brain.target;
}

Circle Agent::GetCollider()
{
	return m_frame.collider;
}