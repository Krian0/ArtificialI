#pragma once
#include "State.h"
#include <stdlib.h>
#include <time.h>

//Enemy will wander in a random direction for 4 seconds, then pick a new direction.
//Switches to Chase if Player is within sight-range.
class WanderState : public State
{
public:
	WanderState() {}
	~WanderState() {}

	void Update(Agent* An_Agent, StateMachine* sm, float DeltaTime) override;
	void Init(Agent* An_Agent) override;
	void Exit(Agent* An_Agent) override;

private:
	//Sets a direction for the Enemy to move
	void SetDirection();

	Vector2 m_direction;
	float m_timer;
};