#include "AttackState.h"
#include "SteeringBehaviour.h"
#include "KeyboardForce.h"
#include "Agent.h"

AttackState::AttackState()
{
	m_keyboard = new KeyboardForce;
}

AttackState::~AttackState()
{
	delete m_keyboard;
}


void AttackState::Update(Agent* An_Agent, StateMachine* sm, float DeltaTime)
{
	vector<Agent*> TargetsInRange = SortTargets(An_Agent, An_Agent->GetTargets());

	//Attack any target Agents in range
	if (m_hasAttacked == false && TargetsInRange.size() > 0)
	{
		for (auto TA : TargetsInRange)
			TA->OnHit();
		
		m_hasAttacked = true;
	}


	//Decrease timer and decide what to do when timer is less than or equal to 0 
	m_waitTimer -= DeltaTime;

	if (m_waitTimer <= 0)
	{
		if (An_Agent->IsAgentPlayer() == false)
		{
			//Work out the distance between Agents
			float Distance = (An_Agent->GetPos() - An_Agent->GetTargets()[0]->GetPos()).magnitude();

			//Change state if the proper conditions are met
			if (An_Agent->WasAttacked() == true)
			{
				sm->ChangeState(An_Agent, StateE::FLEE);
				return;
			}

			if (Distance > An_Agent->m_sightRange)
			{
				sm->ChangeState(An_Agent, StateE::WANDER);
				return;
			}

			if (Distance <= An_Agent->m_sightRange)
			{
				sm->ChangeState(An_Agent, StateE::CHASE);
				return;
			}
		}

		//Otherwise, reset the wait timer and set has attacked to false (allow Agent to attack again)
		m_waitTimer = 0.2f;
		m_hasAttacked = false;
	}
}

void AttackState::Init(Agent* An_Agent)
{
	m_waitTimer = 0.2f;
	m_hasAttacked = false;

	if (An_Agent->IsAgentPlayer() == true)
		An_Agent->AddSteering(SteeringE::KEYBOARD, m_keyboard);
}

void AttackState::Exit(Agent* An_Agent)
{
	An_Agent->RemoveSteering(SteeringE::KEYBOARD);
}


vector<Agent*> AttackState::SortTargets(Agent* An_Agent, vector<Agent*> Targets)
{
	vector<Agent*> TargetsInRange;

	for (auto TA : Targets)
	{
		Vector2 Pos = TA->GetPos() - An_Agent->GetPos();

		float TargetRadius = TA->GetRadius();
		float CombinedRadiiSquared = (An_Agent->m_attackRange + TargetRadius) * (An_Agent->m_attackRange + TargetRadius);

		//Check if any target Agents are within range, and add them to the TargetsInRange vector if they are
		if (Pos.dot(Pos) <= CombinedRadiiSquared)
			TargetsInRange.push_back(TA);
	}

	return TargetsInRange;
}