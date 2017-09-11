#include "StateMachine.h"
#include "Agent.h"

StateMachine::StateMachine(vector<State*> Available_States, Agent* An_Agent)
{
	m_availableStates	= Available_States;

	m_availableStates[(int)StateEnum::WANDER]->Init(An_Agent);
	m_currentState = m_availableStates[(int)StateEnum::WANDER];
}

StateMachine::~StateMachine()
{
	
}


void StateMachine::Update(Agent* An_Agent, float DeltaTime)
{
	m_currentState->Update(An_Agent, this, DeltaTime);
}

void StateMachine::ChangeState(Agent* An_Agent, StateEnum A_State)
{
	m_currentState->Exit(An_Agent);
	m_availableStates[(int)A_State]->Init(An_Agent);

	m_previousState = m_currentState;
	m_currentState = m_availableStates[(int)A_State];
}

void StateMachine::ReturnToLastState()
{
	m_currentState = m_previousState;
}

State* StateMachine::GetCurrentState()
{
	return m_currentState;
}

State* StateMachine::GetPrevState()
{
	return m_previousState;
}