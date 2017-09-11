#pragma once
#include "StateMachine.h"
#include "Vector2.h"

class StateMachine;
class Agent;

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