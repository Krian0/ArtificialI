#pragma once
#include "SteeringForce.h"

class SeekForce : SteeringForce
{
public:
	SeekForce();
	~SeekForce();

	Vector2 GetForce(Agent* An_Agent) override;

private:

};