#include "FleeState.h"

void FleeState::Update(Agent* An_Agent, StateMachine* sm, float DeltaTime)
{
	//Work out the distance from Enemy to Player
	Vector2 TargetPos = An_Agent->GetTargetPos();
	Vector2 AgentPos = An_Agent->GetPos();
	float Distance = (AgentPos - TargetPos).magnitude();
	//~


	//Change state if the proper conditions are met
	if (Distance > An_Agent->m_sightRange * 2)
	{
		sm->ChangeState(An_Agent, WANDER);
		return;
	}
	//~


	//Otherwise, move Enemy away from Player (continue to flee)
	else
	{
		Vector2 Force = ((AgentPos - TargetPos).normalise() * An_Agent->m_velocityLimit);
		An_Agent->AddForce((Force - An_Agent->GetCurrentVelocity()));
	}
	//~
}

void FleeState::Init(Agent* An_Agent)
{
	An_Agent->OnFlee();
}

void FleeState::Exit(Agent* An_Agent)
{

}