#pragma once
#include "State.h"

//Enemy will attack the Player and wait 1 second before deciding whether to attack again or change state.
//Switches to Chase if Player is within sight-range but outside of attack-range, switches to Wander if Player is outside of sight-range. 
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