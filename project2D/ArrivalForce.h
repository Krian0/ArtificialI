#pragma once
#include "SteeringForce.h"
#include <vector>
using std::vector;

class ArrivalForce : public SteeringForce
{
public:
	ArrivalForce();
	~ArrivalForce();

	//Returns a Vector2 Force that slows the given Agent* as they approach the Player, other Enemies and Objects. Takes an Agent* as parameter
	Vector2 GetForce(Agent* An_Agent) override;

private:

	//Return the Agent* from the Friends Agent* vector that is closest to the given Agent*. Takes an Agent* as parameter
	Agent* GetClosestFriend(vector<Agent*> Friends, Agent* An_Agent);
};