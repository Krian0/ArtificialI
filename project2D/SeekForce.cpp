#include "SeekForce.h"

SeekForce::SeekForce()
{
}

SeekForce::~SeekForce()
{
}


Vector2 SeekForce::GetForce(Agent* An_Agent)
{
	Vector2 TargetPos = An_Agent->GetTargetPos();
	Vector2 AgentPos = An_Agent->GetPos();
	Vector2 Force = ((TargetPos - AgentPos).normalise() * An_Agent->m_velocityLimit);
	
	return Force - An_Agent->GetCurrentVelocity();
}