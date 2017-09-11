#pragma once
#include "State.h"

//Enemy will flee from the Player after being hit until conditions to change state are met.
//Switches to Wander if the Player is outside of sight-range.
class FleeState : public State
{
public:
	FleeState();
	~FleeState();

	void Update(Agent* An_Agent, StateMachine* sm, float DeltaTime) override;
	void Init(Agent* An_Agent) override;
	void Exit(Agent* An_Agent) override;

private:

};