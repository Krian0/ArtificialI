#pragma once
#include "SteeringForce.h"

class EvadeForce : public SteeringForce
{
public:
	EvadeForce();
	~EvadeForce();

	Vector2 GetForce(Agent* An_Agent) override;

private:

	vector<Agent*> FindClosestFriends(vector<Agent*> Friends, Agent* An_Agent);

};