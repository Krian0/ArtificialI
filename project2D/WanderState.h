#pragma once
#include "State.h"
#include <stdlib.h>
#include <time.h>

class WanderForce;
class EvadeForce;
class AvoidForce;

//Enemy will wander in a random direction.
//Switches to : Chase if Player is within sight-range.
class WanderState : public State
{
public:
	WanderState();
	~WanderState();

	//Checks if State should change. Takes an Agent*, a StateMachine* and a float as parameters
	void Update(Agent* An_Agent, StateMachine* sm, float DeltaTime) override;
	
	//Adds Wander, Evade and Avoid SteeringForce to given Agent. Takes an Agent* as parameter
	void Init(Agent* An_Agent) override;
	
	//Removes Wander SteeringForce from given Agent. Takes an Agent* as parameter
	void Exit(Agent* An_Agent) override;

private:

	WanderForce* m_wander;
	EvadeForce*  m_evade;
	AvoidForce*  m_avoid;
};