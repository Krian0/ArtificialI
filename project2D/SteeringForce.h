#pragma once
#include "Agent.h"

class SteeringForce
{
public:
	SteeringForce() {};
	~SteeringForce() {};

	//Return Vector2 Force. Takes an Agent* parameter
	virtual Vector2 GetForce(Agent* An_Agent) = 0;
	
	//Return float m_weight
	float GetWeight();

protected:

	float m_weight;
};