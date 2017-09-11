#include "FleeForce.h"

FleeForce::FleeForce()
{
}

FleeForce::~FleeForce()
{
}

Vector2 FleeForce::GetForce(Agent* An_Agent)
{
	Vector2 TargetPos = An_Agent->GetTargetPos();
	Vector2 AgentPos = An_Agent->GetPos();
	Vector2 Force = ((AgentPos - TargetPos).normalise() * An_Agent->m_velocityLimit);

	return Force - An_Agent->GetCurrentVelocity();
}