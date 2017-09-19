#include "Agent.h"
#include "SteeringBehaviour.h"

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


//Set Functions
void Agent::SetTargetList(vector<Agent*> Targets)
{
	m_targets = Targets;
}

void Agent::AddFriendToList(Agent* Friend)
{
	m_friends.push_back(Friend);
}

void Agent::AddSteering(SteeringE Steering_Enum, SteeringForce* Steering_Force)
{
	dynamic_cast<SteeringBehaviour*>(m_behaviours.at(BehaviourE::STEERING))->AddSteering(Steering_Enum, Steering_Force);
}

void Agent::RemoveSteering(SteeringE Steering_Enum)
{
	dynamic_cast<SteeringBehaviour*>(m_behaviours.at(BehaviourE::STEERING))->RemoveSteering(Steering_Enum);
}


//Get Functions
vector<Agent*> Agent::GetTargets()
{
	return m_targets;
}

vector<Agent*> Agent::GetFriends()
{
	return m_friends;
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