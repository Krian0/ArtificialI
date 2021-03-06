#include "StateMachine.h"
#include "WanderState.h"
#include "AttackState.h"
#include "ChaseState.h"
#include "StateEnum.h"
#include "FleeState.h"
#include "Agent.h"

StateMachine::StateMachine(Agent* An_Agent, StateE Start_State)
{
	m_availableStates[StateE::ATTACK]	= new AttackState;
	m_availableStates[StateE::WANDER]	= new WanderState;
	m_availableStates[StateE::CHASE]	= new ChaseState;
	m_availableStates[StateE::FLEE]		= new FleeState;

	m_availableStates[Start_State]->Init(An_Agent);
	m_currentState = m_availableStates[Start_State];
}

StateMachine::~StateMachine()
{
	m_availableStates.clear();
}


void StateMachine::Update(Agent* An_Agent, float DeltaTime)
{
	m_currentState->Update(An_Agent, this, DeltaTime);
}

void StateMachine::ChangeState(Agent* An_Agent, StateE A_State)
{
	m_currentState->Exit(An_Agent);
	m_availableStates[A_State]->Init(An_Agent);

	m_currentState = m_availableStates[A_State];
}

State* StateMachine::GetCurrentState()
{
	return m_currentState;
}