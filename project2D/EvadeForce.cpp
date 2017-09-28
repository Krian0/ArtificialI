#include "EvadeForce.h"

EvadeForce::EvadeForce()
{
	m_weight = 2.00;
}

EvadeForce::~EvadeForce()
{
}


Vector2 EvadeForce::GetForce(Agent* An_Agent)
{
	Agent* ClosestFriend = FindClosestFriend(An_Agent->GetFriends(), An_Agent);

	Vector2 Force(0, 0);

	if (ClosestFriend != nullptr)
	{
			Vector2 V = An_Agent->GetPos() - ClosestFriend->GetPos() + ClosestFriend->GetCurrentVelocity();
			Vector2 Normalized_V = V.normalise() * (float)An_Agent->m_velocityLimit;
			Vector2 TempForce = (Normalized_V - An_Agent->GetCurrentVelocity());

			Force = TempForce;
	}

	return Force;
}

Agent* EvadeForce::FindClosestFriend(vector<Agent*> Friends, Agent* An_Agent)
{
	Agent* FriendInRange = nullptr;

	for (unsigned int i = 0; i < Friends.size(); i++)
	{
		if (Friends[i] != nullptr)
		{
			Vector2 Pos = Friends[i]->GetPos() - An_Agent->GetPos();

			float TargetRadius = Friends[i]->GetRadius();
			float CombinedRadiiSquared = (An_Agent->m_attackRange + TargetRadius) * (An_Agent->m_attackRange + TargetRadius);

			//Check if any friend Agents are within range, and add them to the FriendsInRange vector if they are
			if (Pos.dot(Pos) <= CombinedRadiiSquared)
				FriendInRange = Friends[i];
		}
	}

	return FriendInRange;
}