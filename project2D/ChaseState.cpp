#include "ChaseState.h"
#include "SteeringBehaviour.h"
#include "SeekForce.h"
#include "Agent.h"

ChaseState::ChaseState()
{
	m_seek = new SeekForce;
}

ChaseState::~ChaseState()
{
	delete m_seek;
}


void ChaseState::Update(Agent* An_Agent, StateMachine* sm, float DeltaTime)
{
	//Work out the distance from Enemy to Player
	Vector2 TargetPos = An_Agent->GetTargets()[0]->GetPos();
	Vector2 AgentPos = An_Agent->GetPos();
	float Distance = (AgentPos - TargetPos).magnitude();
	//~


	//Change state if the proper conditions are met
	if (Distance > An_Agent->m_sightRange)
	{
		sm->ChangeState(An_Agent, StateE::WANDER);
		return;
	}

	if (Distance <= An_Agent->m_attackRange)
		sm->ChangeState(An_Agent, StateE::ATTACK);
	//~


	//Otherwise, continue to chase
}

void ChaseState::Init(Agent* An_Agent)
{
	An_Agent->AddSteering(SteeringE::SEEK, m_seek);
}

void ChaseState::Exit(Agent* An_Agent)
{
	An_Agent->RemoveSteering(SteeringE::SEEK);
}