#pragma once
#include "State.h"

class KeyboardForce;

//Agent will attack any targets in range and wait 0.2 seconds before deciding whether to attack again or change state. Only Enemies will switch states.
//Switches to : Flee if the Enemy has been hit, Wander if Player is outside of sight-range, Chase if Player is within sight-range.
class AttackState : public State
{
public:
	AttackState();
	~AttackState();

	void Update(Agent* An_Agent, StateMachine* sm, float DeltaTime) override;
	void Init(Agent* An_Agent) override;
	void Exit(Agent* An_Agent) override;

private:

	vector<Agent*> SortTargets(Agent* An_Agent, vector<Agent*> Targets);

	KeyboardForce* m_keyboard;

	float	m_waitTimer;
	bool	m_hasAttacked;
};