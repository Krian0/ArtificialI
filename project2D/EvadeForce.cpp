#include "EvadeForce.h"

EvadeForce::EvadeForce()
{
	m_weight = 1.0;
}

EvadeForce::~EvadeForce()
{
}


Vector2 EvadeForce::GetForce(Agent* An_Agent)
{
	Vector2 AgentPos = An_Agent->GetPos();

	vector<Agent*> Friends = FindClosestFriend(An_Agent->GetFriends(), AgentPos);

	if (Friends != NULL)
	{
		Vector2 V = AgentPos - Friend->GetPos() + Friend->GetCurrentVelocity();
		Vector2 Normalized_V = V.normalise() * (float)An_Agent->m_velocityLimit;
		Vector2 Force = (Normalized_V - An_Agent->GetCurrentVelocity());

		return Force - An_Agent->GetCurrentVelocity();
	}

	return Vector2(0, 0);
}

vector<Agent*> EvadeForce::FindClosestFriends(vector<Agent*> Friends, Agent* An_Agent)
{
	vector<Agent*> FriendsInRange;

	for (unsigned int i = 0; i < Friends.size(); i++)
	{
		if (Friends[i] != NULL)
		{
			Vector2 Pos = Friends[i]->GetPos() - An_Agent->GetPos();

			float TargetRadius = Friends[i]->GetRadius();
			float CombinedRadiiSquared = (An_Agent->m_attackRange + TargetRadius) * (An_Agent->m_attackRange + TargetRadius);

			//Check if any friend Agents are within range, and add them to the FriendsInRange vector if they are
			if (Pos.dot(Pos) <= CombinedRadiiSquared)
				FriendsInRange.push_back(Friends[i]);
			//~
		}
	}

	return FriendsInRange;
}