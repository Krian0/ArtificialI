#pragma once
#include "SteeringForce.h"

class FleeForce : public SteeringForce
{
public:
	FleeForce();
	~FleeForce();

	Vector2 GetForce(Agent* An_Agent) override;

private:

};