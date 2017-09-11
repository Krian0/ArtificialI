#pragma once
#include "State.h"
#include "StateEnum.h"
#include <vector>
using std::vector;

class State;
class Agent;

class StateMachine
{
public:
	StateMachine(vector<State*> Available_States, Agent* An_Agent);
	~StateMachine();

	void Update(Agent* An_Agent, float DeltaTime);
	void ChangeState(Agent* An_Agent, StateEnum A_State);
	void ReturnToLastState();

	State* GetCurrentState();
	State* GetPrevState();

	vector<State*>		m_availableStates;

private:
	State* m_currentState;
	State* m_previousState;

};