#include "WanderState.h"

void WanderState::Update(Agent* An_Agent, StateMachine* sm, float DeltaTime)
{

}

void WanderState::Init(Agent* An_Agent)
{
	Vector2 AgentPos = An_Agent->GetPos();
	const int Range = 40;

	UpPos.y		+= Range;
	DownPos.y	-= Range;
	LeftPos.x	+= Range;
	RightPos.x	-= Range;

	//get random direction from rand 1-4, continue with it until current pos is at or outside those bounds
	//account for window borders, make it go the opposite direction should it hit a border
}

void WanderState::Exit(Agent* An_Agent)
{

}