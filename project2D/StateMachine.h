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

	//Updates current State. Takes an Agent* parameter and a float parameter
	void Update(Agent* An_Agent, float DeltaTime);
	//Exits current State and Initializes next State. Takes an Agent* parameter and a StateE (enum) parameter  
	void ChangeState(Agent* An_Agent, StateE A_State);

	State* GetCurrentState();

private:
	
	map<StateE, State*>	m_availableStates;
	State* m_currentState;

};