#pragma once
#include "SteeringForce.h"
#include <stdlib.h>
#include <time.h>

class WanderForce : public SteeringForce
{
public:
	WanderForce();
	~WanderForce();

	Vector2 GetForce(Agent* An_Agent) override;

private:

	float m_wanderRadius;
	float m_wanderDistance;
	float m_wanderJitter;

	Vector2 m_previousTarget;

};