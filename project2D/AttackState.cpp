#include "AttackState.h"

void AttackState::Update(Agent* An_Agent, StateMachine* sm, float DeltaTime)
{
	//Attack player only once
	if (m_hasAttacked == false)
	{
		An_Agent->GetTarget.OnHit();
		m_hasAttacked = true;
	}
	//~


	//Decrease timer and change state if timer is equal to or less than 0 
	m_waitTimer -= DeltaTime;

	if (m_waitTimer <= 0)
	{
		//Find distance from enemy to player and the enemy sightrange squared
		Vector2 TargetPos = An_Agent->GetTargetPos();
		Vector2 AgentPos = An_Agent->GetPos();

		float Distance = AgentPos.dot(TargetPos);
		float SightRange = An_Agent->m_sightRange * An_Agent->m_sightRange;
		//~


		if (Distance > SightRange)
			sm->ChangeState(An_Agent, WANDER);

		else if (Distance > An_Agent->m_attackRange)
			sm->ChangeState(An_Agent, CHASE);

		else
		{
			m_waitTimer = 1;
			m_hasAttacked = false;
		}
	}
	//~
}

void AttackState::Init(Agent* An_Agent)
{
	m_waitTimer = 1;
	m_hasAttacked = false;
}

void AttackState::Exit(Agent* An_Agent)
{

}