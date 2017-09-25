#include "ArrivalForce.h"
#include <algorithm>
using std::min;

ArrivalForce::ArrivalForce()
{
	m_weight = 0.75;
}

ArrivalForce::~ArrivalForce()
{
}

Vector2 ArrivalForce::GetForce(Agent* An_Agent)
{
	//Player ArrivalForce calculations
	Vector2 PPos = An_Agent->GetTargets()[0]->GetPos() - An_Agent->GetPos();
	float PDistance = PPos.magnitude();

	Vector2 Force(0, 0);

	if (PDistance <= 120)
	{
		float V = min(PDistance, (float)An_Agent->m_velocityLimit);
		Force += Vector2(V, V);
	}
	//~


	//Friend ArrivalForce calculations
	Agent* ClosestFriend = GetClosestFriend(An_Agent->GetFriends(), An_Agent);

	if (ClosestFriend == NULL)
		return Vector2(0, 0);

	Vector2 FPos = An_Agent->GetTargets()[0]->GetPos() - An_Agent->GetPos();
	float FDistance = FPos.magnitude();

	if (FDistance <= 100)
	{
		float V = min(FDistance, (float)An_Agent->m_velocityLimit);
		Force += Vector2(V, V);
	}
	//~


	return Force - An_Agent->GetCurrentVelocity();
}

Agent* ArrivalForce::GetClosestFriend(vector<Agent*> Friends, Agent* An_Agent)
{
	Agent* ClosestFriend = NULL;
	float PreviousDistance = 9999999;

	for (unsigned int i = 0; i < Friends.size(); i++)
	{
		float CurrentDistance = (An_Agent->GetPos() - Friends[i]->GetPos()).magnitude();

		if (CurrentDistance < PreviousDistance)
			ClosestFriend = Friends[i];
	}

	return ClosestFriend;
}