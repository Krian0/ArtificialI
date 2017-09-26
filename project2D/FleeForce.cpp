#include "FleeForce.h"

FleeForce::FleeForce()
{
	m_weight = 0.70f;
}

FleeForce::~FleeForce()
{
}

Vector2 FleeForce::GetForce(Agent* An_Agent)
{
	Vector2 TargetPos = An_Agent->GetTargets()[0]->GetPos();
	Vector2 AgentPos = An_Agent->GetPos();
	Vector2 Force = ((AgentPos - TargetPos).normalise() * (float)An_Agent->m_velocityLimit);

	return Force - An_Agent->GetCurrentVelocity();
}