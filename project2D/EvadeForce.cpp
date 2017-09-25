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
	vector<Agent*> Friends = FindClosestFriends(An_Agent->GetFriends(), An_Agent);

	if (Friends.size() == 0)
		return Vector2(0, 0);

	Vector2 Force(0, 0);

	for (unsigned int i = 0; i < Friends.size(); i++)
	{
		Vector2 V = An_Agent->GetPos() - Friends[i]->GetPos() + Friends[i]->GetCurrentVelocity();
		Vector2 Normalized_V = V.normalise() * (float)An_Agent->m_velocityLimit;
		Vector2 TempForce = (Normalized_V - An_Agent->GetCurrentVelocity());

		Force += TempForce - An_Agent->GetCurrentVelocity();
	}

	return Force;
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