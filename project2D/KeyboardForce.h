#pragma once
#include "SteeringForce.h"
#include "Input.h"

class KeyboardForce : public SteeringForce
{
public:
	KeyboardForce();
	~KeyboardForce();

	Vector2 GetForce(Agent* An_Agent) override;

private:

};