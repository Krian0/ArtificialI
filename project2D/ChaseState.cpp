#include "ChaseState.h"
#include "Agent.h"

ChaseState::ChaseState()
{

}

ChaseState::~ChaseState()
{

}


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
		sm->ChangeState(An_Agent, StateEnum::WANDER);
		return;
	}

	if (Distance <= An_Agent->m_attackRange)
		sm->ChangeState(An_Agent, StateEnum::ATTACK);
	//~


	//Otherwise, continue to chase
}

void ChaseState::Init(Agent* An_Agent)
{
	//change steering
}

void ChaseState::Exit(Agent* An_Agent)
{

}