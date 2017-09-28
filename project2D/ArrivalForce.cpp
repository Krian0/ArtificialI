#include "ArrivalForce.h"
#include <algorithm>
using std::min;

ArrivalForce::ArrivalForce()
{
	m_weight = 1.00;
}

ArrivalForce::~ArrivalForce()
{
}

Vector2 ArrivalForce::GetForce(Agent* An_Agent)
{
	float speedMultiplier = 1;
	Vector2 Force(0, 0);


	//Player ArrivalForce calculations
	Vector2 PPos = An_Agent->GetTargets()[0]->GetPos() - An_Agent->GetPos();
	float PDistance = PPos.magnitude();

	if (PDistance <= 120)
	{
		speedMultiplier = PDistance / 120;
		Force += An_Agent->GetCurrentVelocity() * -1 * (1 - speedMultiplier);
	}


	//Friend ArrivalForce calculations
	Agent* ClosestFriend = GetClosestFriend(An_Agent->GetFriends(), An_Agent);

	if (ClosestFriend != NULL)
	{
		Vector2 FPos = An_Agent->GetTargets()[0]->GetPos() - An_Agent->GetPos();
		float FDistance = FPos.magnitude();

		if (FDistance <= 80)
		{
			speedMultiplier = FDistance / 80;
			Force += An_Agent->GetCurrentVelocity() * -1 * (1 - speedMultiplier);
		}
	}

	//Node ArrivalForce calculations
	Vector2 NPos(0, 0);
	if (An_Agent->m_currentlySeeking != Vector2(0, 0))
		NPos = An_Agent->m_currentlySeeking - An_Agent->GetPos();
	
	float NDistance = NPos.magnitude();
	if (NDistance <= 400)
	{
		speedMultiplier = NDistance / 400;
		Force += An_Agent->GetCurrentVelocity() * -1 * (1-speedMultiplier);
	}


	return Force;
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