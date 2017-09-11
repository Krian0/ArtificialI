#include "ChaseState.h"

void ChaseState::Update(Agent* An_Agent, StateMachine* sm, float DeltaTime)
{
	//Work out the distance from Enemy to Player
	Vector2 TargetPos = An_Agent->GetTargetPos();
	Vector2 AgentPos = An_Agent->GetPos();
	float Distance = (AgentPos - TargetPos).magnitude();
	//~


	//Change state if the proper conditions are met
	if (Distance > An_Agent->m_sightRange)
	{
		sm->ChangeState(An_Agent, WANDER);
		return;
	}

	if (Distance <= An_Agent->m_attackRange)
	{
		sm->ChangeState(An_Agent, ATTACK);
		return;
	}
	//~


	//Otherwise, move enemy towards Player (continue to chase)
	else
		
	//~
}

void ChaseState::Init(Agent* An_Agent)
{

}

void ChaseState::Exit(Agent* An_Agent)
{

}