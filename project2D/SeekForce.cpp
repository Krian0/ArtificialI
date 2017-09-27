#include "SeekForce.h"

SeekForce::SeekForce()
{
	m_weight = 0.80;
}

SeekForce::~SeekForce()
{
}


Vector2 SeekForce::GetForce(Agent* An_Agent)
{
	Vector2 Force;
	Vector2 TargetPos;
	Vector2 AgentPos = An_Agent->GetPos();
	
	if (An_Agent->PathfindingModeIsOn() == false)
		TargetPos = An_Agent->GetTargets()[0]->GetPos();

	else
	{
		if (m_pathfindingTargets.size() == 0)
			m_pathfindingTargets = An_Agent->GetPathfindingVectors();

		TargetPos = m_pathfindingTargets.top();
		An_Agent->m_currentlySeeking = TargetPos;

		if (An_Agent->IsCollidingWithNode(TargetPos) == true)
			m_pathfindingTargets.pop();
	}

		Force = ((TargetPos - AgentPos).normalise() * (float)An_Agent->m_velocityLimit);
		return Force - An_Agent->GetCurrentVelocity();
}