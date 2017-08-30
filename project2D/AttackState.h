#pragma once
#include "State.h"

class AttackState : public State
{
public:
	AttackState() {}
	~AttackState() {}

	void Update(Agent* An_Agent, StateMachine* sm, float DeltaTime) override;
	void Init(Agent* An_Agent) override;
	void Exit(Agent* An_Agent) override;

private:

	float	m_waitTimer;
	bool	m_hasAttacked;
};