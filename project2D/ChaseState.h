#pragma once
#include "State.h"

//Enemy will chase the Player until conditions to change state are met.
//Switches to : Wander if the Player is outside of sight-range, Attack if the Player is within attack-range.
class ChaseState : public State
{
public:
	ChaseState();
	~ChaseState();

	void Update(Agent* An_Agent, StateMachine* sm, float DeltaTime) override;
	void Init(Agent* An_Agent) override;
	void Exit(Agent* An_Agent) override;

private:

};