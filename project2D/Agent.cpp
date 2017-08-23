#include "Agent.h"

void Agent::AddForce(Vector2 force)
{
	m_frame.force = force;
}

//Get Functions
Vector2 Agent::GetPos()
{
	return m_frame.position;
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