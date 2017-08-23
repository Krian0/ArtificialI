#pragma once
#include "State.h"

class ChaseState : public State
{
public:
	ChaseState() {}
	~ChaseState() {}

	void Update(Agent* An_Agent, StateMachine* sm) override;
	void Init(Agent* An_Agent) override;
	void Exit(Agent* An_Agent) override;

private:

};