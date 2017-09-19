#include "SeekForce.h"

SeekForce::SeekForce()
{
	m_weight = 0.5;
}

SeekForce::~SeekForce()
{
}


Vector2 SeekForce::GetForce(Agent* An_Agent)
{
	Vector2 TargetPos = An_Agent->GetTargets()[0]->GetPos();
	Vector2 AgentPos = An_Agent->GetPos();
	Vector2 Force = ((TargetPos - AgentPos).normalise() * (float)An_Agent->m_velocityLimit);
	
	return Force - An_Agent->GetCurrentVelocity();
}