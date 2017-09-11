#include "FleeState.h"
#include "Agent.h"

FleeState::FleeState()
{

}

FleeState::~FleeState()
{

}


void FleeState::Update(Agent* An_Agent, StateMachine* sm, float DeltaTime)
{
	//Work out the distance from Enemy to Player
	Vector2 TargetPos = An_Agent->GetTargetPos();
	Vector2 AgentPos = An_Agent->GetPos();
	float Distance = (AgentPos - TargetPos).magnitude();
	//~


	//Change state if the proper conditions are met
	if (Distance > An_Agent->m_sightRange * 2)
		sm->ChangeState(An_Agent, StateEnum::WANDER);
	//~


	//Otherwise, continue to flee
}

void FleeState::Init(Agent* An_Agent)
{
	An_Agent->OnFlee();
	//Change Steering
}

void FleeState::Exit(Agent* An_Agent)
{

}