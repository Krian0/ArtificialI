#include "WanderState.h"
#include "SteeringBehaviour.h"
#include "AvoidForce.h"
#include "WanderForce.h"
#include "EvadeForce.h"
#include "Agent.h"

WanderState::WanderState() 
{
	m_wander	= new WanderForce;
	m_evade		= new EvadeForce;
	m_avoid		= new AvoidForce;
}

WanderState::~WanderState() 
{
	delete m_wander;
	delete m_evade;
}


void WanderState::Update(Agent* An_Agent, StateMachine* sm, float DeltaTime)
{
	//Work out the distance from Enemy to Player
	float Distance = (An_Agent->GetPos() - An_Agent->GetTargets()[0]->GetPos()).magnitude();
	//~

	//Change state if the proper conditions are met
	if (Distance <= An_Agent->m_sightRange || An_Agent->PathfindingModeIsOn() == true)
	{
		sm->ChangeState(An_Agent, StateE::CHASE);
		return;
	}
	//~

	//Otherwise, continue to wander
}

void WanderState::Init(Agent* An_Agent)
{
	An_Agent->AddSteering(SteeringE::WANDER, m_wander);
	An_Agent->AddSteering(SteeringE::EVADE, m_evade);
	An_Agent->AddSteering(SteeringE::AVOID, m_avoid);
}

void WanderState::Exit(Agent* An_Agent)
{
	An_Agent->RemoveSteering(SteeringE::WANDER);
}