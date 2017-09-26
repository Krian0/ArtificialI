#include "Agent.h"
#include "BoxObject.h"
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
		CollidePlus(Max.y, VelocityDegrade, m_position.y, m_velocity.y, UsingAgent);

	if (m_position.y <= Min.y)
		CollideMinus(Min.y, VelocityDegrade, m_position.y, m_velocity.y, UsingAgent);


	if (m_position.x > Max.x)
		CollidePlus(Max.x, VelocityDegrade, m_position.x, m_velocity.x, UsingAgent);

	if (m_position.x <= Min.x)
		CollideMinus(Min.x, VelocityDegrade, m_position.x, m_velocity.x, UsingAgent);
}

void Agent::OnCollide(Vector2 OtherAgentPos)
{
	OnCollide(OtherAgentPos, OtherAgentPos, true);
}

void Agent::OnCollide(BoxObject* Object, float VelocityDegrade)
{
	Vector2 Min = Object->GetMin();
	Vector2 Max = Object->GetMax();

	if (m_position.y > Max.y)
		CollidePlus(Max.y + m_radius + 2, VelocityDegrade, m_position.y, m_velocity.y, false);

	if (m_position.y <= Min.y)
		CollideMinus(Min.y - (m_radius + 2), VelocityDegrade, m_position.y, m_velocity.y, false);

	if (m_position.x > Max.x)
		CollidePlus(Max.x + m_radius + 2, VelocityDegrade, m_position.x, m_velocity.x, false);

	if (m_position.x <= Min.x)
		CollideMinus(Min.x - (m_radius + 2), VelocityDegrade, m_position.x, m_velocity.x, false);
}


//Set Functions
void Agent::SetPathfindingMode(bool BooleanValue)
{
	m_pathfindingMode = BooleanValue;
}

void Agent::SetTargetList(vector<Agent*> Targets)
{
	m_targets = Targets;
}

void Agent::AddFriendToList(Agent* Friend)
{
	m_friends.push_back(Friend);
}

void Agent::AddObjects(vector<BoxObject*> Objects)
{
	m_objects = Objects;
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

vector<BoxObject*> Agent::GetObjects()
{
	return m_objects;
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

bool Agent::PathfindingModeIsOn()
{
	return m_pathfindingMode;
}


void Agent::CollidePlus(float Boundary, float DegradeValue, float &Pos, float &Vel, bool UsingAgent)
{
	if (UsingAgent == false)
		Pos = Boundary;

	if (UsingAgent == true)
		Pos += 1;

	Vel = -(Vel * DegradeValue);
}

void Agent::CollideMinus(float Boundary, float DegradeValue, float &Pos, float &Vel, bool UsingAgent)
{
	if (UsingAgent == false)
		Pos = Boundary;

	if (UsingAgent == true)
		Pos -= 1;

	Vel = -(Vel * DegradeValue);
}