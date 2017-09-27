#include "FleeState.h"
#include "SteeringBehaviour.h"
#include "FleeForce.h"
#include "Agent.h"

FleeState::FleeState()
{
	m_flee = new FleeForce;
}

FleeState::~FleeState()
{
	delete m_flee;
}


void FleeState::Update(Agent* An_Agent, StateMachine* sm, float DeltaTime)
{
	//Work out the distance from Enemy to Player
	Vector2 TargetPos = An_Agent->GetTargets()[0]->GetPos();
	Vector2 AgentPos = An_Agent->GetPos();
	float Distance = (AgentPos - TargetPos).magnitude();
	//~


	//Change state if the proper conditions are met
	if (Distance > An_Agent->m_sightRange * 1.10)
		sm->ChangeState(An_Agent, StateE::WANDER);
	//~


	//Otherwise, continue to flee
}

void FleeState::Init(Agent* An_Agent)
{
	An_Agent->RemoveSteering(SteeringE::ARRIVAL);

	An_Agent->OnFlee();
	An_Agent->AddSteering(SteeringE::FLEE, m_flee);
}

void FleeState::Exit(Agent* An_Agent)
{
	An_Agent->RemoveSteering(SteeringE::FLEE);
}