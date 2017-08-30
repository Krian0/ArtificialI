#pragma once
#include "Agent.h"
#include "StateMachine.h"

class State
{
public:
	State() {}
	~State() {}

	virtual void Update(Agent* An_Agent, StateMachine* sm, float DeltaTime) = 0;
	virtual void Init(Agent* An_Agent) = 0;
	virtual void Exit(Agent* An_Agent) = 0;

private:

};