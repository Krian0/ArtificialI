#pragma once
#include "SteeringForce.h"

class KeyboardForce : public SteeringForce
{
public:
	KeyboardForce();
	~KeyboardForce();

	//Returns Vector2 Force that moves given Agent* (Player) up, down, left or right based on input. Takes an Agent* as parameter.
	Vector2 GetForce(Agent* An_Agent) override;
};