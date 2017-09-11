#pragma once
#include "SteeringForce.h"

class SeekForce : public SteeringForce
{
public:
	SeekForce();
	~SeekForce();

	Vector2 GetForce(Agent* An_Agent) override;

private:

};