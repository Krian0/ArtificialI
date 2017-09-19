#pragma once
#include "Agent.h"

class SteeringForce
{
public:
	SteeringForce() {};
	~SteeringForce() {};

	virtual Vector2 GetForce(Agent* An_Agent) = 0;
	float GetWeight();

protected:

	float m_weight;

private:

};