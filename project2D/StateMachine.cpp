#include "StateMachine.h"

StateMachine::StateMachine(vector<State*> Available_States, map<StateEnum, int> State_Map)
{
	m_availableStates	= Available_States;
	m_stateMap			= State_Map;
}

StateMachine::~StateMachine()
{
	
}


void StateMachine::Update(Agent* An_Agent)
{
	m_currentState->Update(An_Agent, this);
}

void StateMachine::ChangeState(Agent* An_Agent, StateEnum A_State)
{
	m_currentState->Exit(An_Agent);
	m_availableStates[m_stateMap.at(A_State)]->Init(An_Agent);

	m_previousState = m_currentState;
	m_currentState = m_availableStates[m_stateMap.at(A_State)];
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