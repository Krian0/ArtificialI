#pragma once
#include "State.h"

class WanderState : public State
{
public:
	WanderState() {}
	~WanderState() {}

	void Update(Agent* An_Agent, StateMachine* sm, float DeltaTime) override;
	void Init(Agent* An_Agent) override;
	void Exit(Agent* An_Agent) override;

private:

	Vector2 UpPos;
	Vector2 DownPos;
	Vector2 LeftPos;
	Vector2 RightPos;

	int Direction;

};