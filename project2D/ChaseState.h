#pragma once
#include "State.h"

class ArrivalForce;
class SeekForce;

//Enemy will chase the Player until conditions to change state are met.
//Switches to : Wander if the Player is outside of sight-range, Attack if the Player is within attack-range.
class ChaseState : public State
{
public:
	ChaseState();
	~ChaseState();

	//Checks if State should change. Takes an Agent*, a StateMachine* and a float as parameters
	void Update(Agent* An_Agent, StateMachine* sm, float DeltaTime) override;
	
	//Adds Seek and Arrival SteeringForce to given Agent. Takes an Agent* as parameter
	void Init(Agent* An_Agent) override;
	
	//Removes Seek SteeringForce from given Agent. Takes an Agent* as parameter
	void Exit(Agent* An_Agent) override;

private:

	ArrivalForce*	m_arrival;
	SeekForce*		m_seek;
};