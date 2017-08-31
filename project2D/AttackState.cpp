#include "AttackState.h"

void AttackState::Update(Agent* An_Agent, StateMachine* sm, float DeltaTime)
{
	//Attack player only once
	if (m_hasAttacked == false)
	{
		An_Agent->GetTarget()->OnHit();
		m_hasAttacked = true;
	}
	//~


	//Decrease timer and decide what to do when timer is less than or equal to 0 
	m_waitTimer -= DeltaTime;

	if (m_waitTimer <= 0)
	{
		//Work out the distance from Enemy to Player and the Enemy's sightrange squared
		Vector2 TargetPos = An_Agent->GetTargetPos();
		Vector2 AgentPos = An_Agent->GetPos();
		float Distance = AgentPos.dot(TargetPos);
		int SightRange = An_Agent->m_sightRange * An_Agent->m_sightRange;
		//~

		//Change state if the proper conditions are met
		if (Distance > SightRange)
			sm->ChangeState(An_Agent, WANDER);

		else if (Distance > An_Agent->m_attackRange)
			sm->ChangeState(An_Agent, CHASE);
		//~


		//Otherwise, reset the wait timer and set has attacked to false (attack again)
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