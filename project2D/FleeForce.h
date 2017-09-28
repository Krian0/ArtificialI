#pragma once
#include "SteeringForce.h"

class FleeForce : public SteeringForce
{
public:
	FleeForce();
	~FleeForce();

	//Returns Vector2 Force that moves the given Agent away from the Player (after being attacked). Takes an Agent* as parameter
	Vector2 GetForce(Agent* An_Agent) override;
};