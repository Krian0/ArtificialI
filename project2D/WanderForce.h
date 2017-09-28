#pragma once
#include "SteeringForce.h"
//#include <stdlib.h>

class WanderForce : public SteeringForce
{
public:
	WanderForce();
	~WanderForce();

	//Returns a Vector2 Force that moves the given Agent* in a random direction. Takes an Agent* as parameter
	Vector2 GetForce(Agent* An_Agent) override;

private:

	float m_wanderRadius;
	float m_wanderDistance;
	float m_wanderJitter;

	Vector2 m_previousTarget;
};