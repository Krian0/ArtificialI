#pragma once
#include "State.h"
#include <stdlib.h>
#include <time.h>

class WanderForce;

//Enemy will wander in a random direction.
//Switches to : Chase if Player is within sight-range.
class WanderState : public State
{
public:
	WanderState();
	~WanderState();

	void Update(Agent* An_Agent, StateMachine* sm, float DeltaTime) override;
	void Init(Agent* An_Agent) override;
	void Exit(Agent* An_Agent) override;

private:

	WanderForce* m_wander;

};