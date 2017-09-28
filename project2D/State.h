#pragma once
class StateMachine;
class Agent;

class State
{
public:
	State() {}
	~State() {}

	//Updates State. Takes an Agent*, a StateMachine* and a float as parameters
	virtual void Update(Agent* An_Agent, StateMachine* sm, float DeltaTime) = 0;
	
	//Initialization for the current State. Takes an Agent* as parameter
	virtual void Init(Agent* An_Agent) = 0;
	
	//Exit code for the current State. Takes an Agent* as parameter
	virtual void Exit(Agent* An_Agent) = 0;
};