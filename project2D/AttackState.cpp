#include "AttackState.h"

void AttackState::Update(Agent* An_Agent, StateMachine* sm, float DeltaTime)
{
	//Attack Player only once
	if (m_hasAttacked == false && TargetIsInRange(An_Agent) == true)
	{
		An_Agent->GetTarget()->OnHit();
		m_hasAttacked = true;
	}
	//~


	//Decrease timer and decide what to do when timer is less than or equal to 0 
	m_waitTimer -= DeltaTime;

	if (m_waitTimer <= 0)
	{
		//Work out the distance from Enemy to Player
		float Distance = (An_Agent->GetPos() - An_Agent->GetTargetPos()).magnitude();
		//~

		//Change state if the proper conditions are met
		if (An_Agent->WasAttacked() == true)
		{
			sm->ChangeState(An_Agent, FLEE);
			return;
		}

		if (Distance > An_Agent->m_sightRange)
		{
			sm->ChangeState(An_Agent, WANDER);
			return;
		}

		else if (Distance <= An_Agent->m_sightRange)
		{
			sm->ChangeState(An_Agent, CHASE);
			return;
		}
		//~


		//Otherwise, reset the wait timer and set has attacked to false (attack again)
		else
		{
			m_waitTimer = 0.2;
			m_hasAttacked = false;
		}
	}
	//~
}

void AttackState::Init(Agent* An_Agent)
{
	m_waitTimer = 0.2;
	m_hasAttacked = false;
}

void AttackState::Exit(Agent* An_Agent)
{

}


bool AttackState::TargetIsInRange(Agent* An_Agent)
{
	Vector2 Pos = An_Agent->GetTargetPos() - An_Agent->GetPos();

	float TargetRadius = An_Agent->GetTarget()->GetRadius();
	float CombinedRadiiSquared = (An_Agent->m_attackRange + TargetRadius) * (An_Agent->m_attackRange + TargetRadius);

	bool ThereIsAnOverlap = false;

	if (Pos.dot(Pos) <= CombinedRadiiSquared)
		ThereIsAnOverlap = true;

	return ThereIsAnOverlap;
}