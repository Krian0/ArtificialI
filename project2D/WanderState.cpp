#include "WanderState.h"
#include "SteeringBehaviour.h"
#include "WanderForce.h"
#include "Agent.h"

WanderState::WanderState() 
{
	m_wander = new WanderForce;
}

WanderState::~WanderState() 
{
	delete m_wander;
}


void WanderState::Update(Agent* An_Agent, StateMachine* sm, float DeltaTime)
{
	//Work out the distance from Enemy to Player
	float Distance = (An_Agent->GetPos() - An_Agent->GetTargets()[0]->GetPos()).magnitude();
	//~

	//Change state if the proper conditions are met
	if (Distance <= An_Agent->m_sightRange)
	{
		sm->ChangeState(An_Agent, StateE::CHASE);
		return;
	}
	//~

	//Otherwise, continue to wander
}

void WanderState::Init(Agent* An_Agent)
{
	auto Steering = dynamic_cast<SteeringBehaviour*>(An_Agent->GetBehaviour(BehaviourE::STEERING));
	Steering->m_steeringForce = m_wander;
}

void WanderState::Exit(Agent* An_Agent)
{

}