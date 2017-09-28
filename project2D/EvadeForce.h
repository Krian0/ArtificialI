#pragma once
#include "SteeringForce.h"
#include <vector>
using std::vector;

class EvadeForce : public SteeringForce
{
public:
	EvadeForce();
	~EvadeForce();

	//Returns a Vector2 Force that moves the given Agent* away from other Friend Agents. Takes an Agent* as parameter
	Vector2 GetForce(Agent* An_Agent) override;

private:

	//Returns the Friend Agent* closest to the given Agent*. Takes an Agent* vector and an Agent* as parameters
	Agent* FindClosestFriend(vector<Agent*> Friends, Agent* An_Agent);
};