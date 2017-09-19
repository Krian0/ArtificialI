#pragma once
#include "State.h"
#include "StateEnum.h"
#include <map>
#include <vector>
using std::map;
using std::vector;

class State;
class Agent;

class StateMachine
{
public:
	StateMachine(Agent* An_Agent, StateE Start_State);
	~StateMachine();

	void Update(Agent* An_Agent, float DeltaTime);
	void ChangeState(Agent* An_Agent, StateE A_State);
	void ReturnToLastState();

	State* GetCurrentState();
	State* GetPrevState();

	map<StateE, State*>	m_availableStates;

private:
	State* m_currentState;
	State* m_previousState;

};