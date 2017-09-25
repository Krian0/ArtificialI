#pragma once
#include "SteeringForce.h"

class ArrivalForce : public SteeringForce
{
public:
	ArrivalForce();
	~ArrivalForce();

	Vector2 GetForce(Agent* An_Agent) override;

private:

	Agent* GetClosestFriend(vector<Agent*> Friends, Agent* An_Agent);

};