#include "StateMachine.h"
#include "Agent.h"

StateMachine::StateMachine(Agent* An_Agent, map<StateE, State*> Available_States, StateE Start_State)
{
	m_availableStates = Available_States;

	m_availableStates[Start_State]->Init(An_Agent);
	m_currentState = m_availableStates[Start_State];
}

StateMachine::~StateMachine()
{
	
}


void StateMachine::Update(Agent* An_Agent, float DeltaTime)
{
	m_currentState->Update(An_Agent, this, DeltaTime);
}

void StateMachine::ChangeState(Agent* An_Agent, StateE A_State)
{
	m_currentState->Exit(An_Agent);
	m_availableStates[A_State]->Init(An_Agent);

	m_previousState = m_currentState;
	m_currentState = m_availableStates[A_State];
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