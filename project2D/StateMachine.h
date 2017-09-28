#pragma once
#include "StateEnum.h"
#include <map>
using std::map;

class State;
class Agent;

class StateMachine
{
public:
	StateMachine(Agent* An_Agent, StateE Start_State);
	~StateMachine();

	//Updates current State. Takes an Agent* and a float as parameters
	void Update(Agent* An_Agent, float DeltaTime);
	//Exits current State and Initializes next State. Takes an Agent* and a StateE (Enum) as parameters
	void ChangeState(Agent* An_Agent, StateE A_State);

	State* GetCurrentState();

private:
	
	map<StateE, State*>	m_availableStates;
	State* m_currentState;
};