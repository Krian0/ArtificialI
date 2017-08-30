#pragma once
#include "Enum.h"
#include "Agent.h"
#include "State.h"
#include "AttackState.h"
#include "WanderState.h"
#include "ChaseState.h"

#include <map>
using std::map;

class StateMachine
{
public:
	StateMachine(vector<State*> Available_States, map<StateEnum, int> State_Map);
	~StateMachine();

	void Update(Agent* An_Agent, float DeltaTime);
	void ChangeState(Agent* An_Agent, StateEnum A_State);
	void ReturnToLastState();

	State *GetCurrentState();
	State *GetPrevState();

	map<StateEnum, int> m_stateMap;
	vector<State*>		m_availableStates;

private:
	State* m_currentState;
	State* m_previousState;

};