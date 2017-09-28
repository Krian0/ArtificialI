#pragma once
#include "State.h"

class FleeForce;

//Enemy will flee from the Player after being hit until conditions to change state are met.
//Switches to Wander if the Player is outside of sight-range.
class FleeState : public State
{
public:
	FleeState();
	~FleeState();

	//Checks if State should change. Takes an Agent*, a StateMachine* and a float as parameters
	void Update(Agent* An_Agent, StateMachine* sm, float DeltaTime) override;
	
	//Remove Arrival, add Flee SteeringForce, and call OnFlee for given Agent. Takes an Agent* as parameter
	void Init(Agent* An_Agent) override;
	
	//Remove Flee SteeringForce from given Agent. Takes an Agent* as parameter
	void Exit(Agent* An_Agent) override;

private:

	FleeForce* m_flee;
};