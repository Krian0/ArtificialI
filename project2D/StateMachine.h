#pragma once
#include "Agent.h"
#include "State.h"
#include <vector>
#include <map>
using std::vector;
using std::map;

enum StateEnum
{
	ATTACK = 0,
	WANDER,
	CHASE,
	FLEE,
	END
};

class State;

class StateMachine
{
public:
	StateMachine(vector<State*> Available_States, map<StateEnum, int> State_Map, Agent* An_Agent);
	~StateMachine();

	void Update(Agent* An_Agent, float DeltaTime);
	void ChangeState(Agent* An_Agent, StateEnum A_State);
	void ReturnToLastState();

	State* GetCurrentState();
	State* GetPrevState();

	map<StateEnum, int> m_stateMap;
	vector<State*>		m_availableStates;

private:
	State* m_currentState;
	State* m_previousState;

};