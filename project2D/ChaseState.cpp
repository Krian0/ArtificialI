#include "ChaseState.h"

void ChaseState::Update(Agent* An_Agent, StateMachine* sm, float DeltaTime)
{
	//Work out the distance from Enemy to Player and the Enemy's sightrange squared
	Vector2 TargetPos = An_Agent->GetTargetPos();
	Vector2 AgentPos = An_Agent->GetPos();
	float Distance = AgentPos.dot(TargetPos);
	int SightRange = An_Agent->m_sightRange * An_Agent->m_sightRange;
	//~


	//Change state if the proper conditions are met
	if (Distance > SightRange)
		sm->ChangeState(An_Agent, WANDER);

	if (Distance <= An_Agent->m_attackRange)
		sm->ChangeState(An_Agent, ATTACK);
	//~


	//Otherwise, move enemy towards player (continue to chase)
	else
	{
		Vector2 Direction = TargetPos - AgentPos;
		Direction.normaliseDirect();
		An_Agent->AddForce(Direction * 100);
	}
	//~
}

void ChaseState::Init(Agent* An_Agent)
{

}

void ChaseState::Exit(Agent* An_Agent)
{

}