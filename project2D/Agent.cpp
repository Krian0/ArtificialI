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
	m_wasAttacked = true;
}

void Agent::OnFlee()
{
	m_wasAttacked = false;
}


//Get Functions
IBehaviour* Agent::GetBehaviour(BehaviourE Index)
{
	return m_behaviours[Index];
}

vector<Agent*> Agent::GetTargets()
{
	return m_targets;
}

Vector2 Agent::GetPos()
{
	return m_position;
}

Vector2 Agent::GetCurrentVelocity()
{
	return m_velocity;
}

float Agent::GetRadius()
{
	return m_radius;
}

bool Agent::WasAttacked()
{
	return m_wasAttacked;
}

bool Agent::IsAgentPlayer()
{
	return m_isPlayer;
}

bool Agent::IsColliding(Agent* The_Target)
{
	Vector2 TargetPos = The_Target->GetPos();
	Vector2 Pos = TargetPos - m_position;

	float TargetRadius = The_Target->GetRadius();
	float CombinedRadiiSquared = (m_radius + TargetRadius) * (m_radius + TargetRadius);

	bool ThereIsAnOverlap = false;

	if (Pos.dot(Pos) <= CombinedRadiiSquared)
		ThereIsAnOverlap = true;

	return ThereIsAnOverlap;
}