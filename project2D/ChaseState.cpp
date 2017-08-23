#include "ChaseState.h"

void ChaseState::Update(Agent* An_Agent, StateMachine* sm)
{
	Vector2 TargetPos = An_Agent->GetTargetPos();
	Vector2 AgentPos = An_Agent->GetPos();

	float Distance = AgentPos.dot(TargetPos);
	float SightRange = An_Agent->m_sightRange * An_Agent->m_sightRange;

	if (Distance > SightRange)
	{
		sm->ChangeState(An_Agent, WANDER);
		return;
	}

	if (Distance < An_Agent->m_attackRange)
	{
		sm->ChangeState(An_Agent, ATTACK);
		return;
	}

	else
	{
		Vector2 Direction = TargetPos - AgentPos;
		Direction.normaliseDirect();
		An_Agent->AddForce(Direction);
	}
}

void ChaseState::Init(Agent* An_Agent)
{

}

void ChaseState::Exit(Agent* An_Agent)
{

}