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

void Agent::OnCollide(Vector2 Min, Vector2 Max, bool UsingAgent, float VelocityDegrade)
{
	if (m_position.y > Max.y)
		CollideMinus(Max.y, VelocityDegrade, m_position.y, m_velocity.y, UsingAgent);

	if (m_position.y <= Min.y)
		CollidePlus(Min.y, VelocityDegrade, m_position.y, m_velocity.y, UsingAgent);


	if (m_position.x > Max.x)
		CollideMinus(Max.x, VelocityDegrade, m_position.x, m_velocity.x, UsingAgent);

	if (m_position.x <= Min.x)
		CollidePlus(Min.x, VelocityDegrade, m_position.x, m_velocity.x, UsingAgent);
}

void Agent::OnCollide(Vector2 OtherAgentPos)
{
	OnCollide(OtherAgentPos, OtherAgentPos, true);
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
	float CombinedRadiiSquared = (m_radius + TargetRadius + 2) * (m_radius + TargetRadius + 2);

	bool ThereIsAnOverlap = false;

	if (Pos.dot(Pos) <= CombinedRadiiSquared)
		ThereIsAnOverlap = true;

	return ThereIsAnOverlap;
}


void Agent::CollidePlus(float Boundary, float DegradeValue, float &Pos, float &Vel, bool UsingAgent)
{
	if (UsingAgent == false)
		Pos = Boundary;

	if (UsingAgent == true)
		Pos -= 1;

	Vel = -(Vel * DegradeValue);
}

void Agent::CollideMinus(float Boundary, float DegradeValue, float &Pos, float &Vel, bool UsingAgent)
{
	if (UsingAgent == false)
		Pos = Boundary;

	if (UsingAgent == true)
		Pos += 1;

	Vel = -(Vel * DegradeValue);
}