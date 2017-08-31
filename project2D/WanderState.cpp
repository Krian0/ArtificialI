#include "WanderState.h"

void WanderState::Update(Agent* An_Agent, StateMachine* sm, float DeltaTime)
{
	//Work out the distance from Enemy to Player and the Enemy's sightrange squared
	Vector2 TargetPos = An_Agent->GetTargetPos();
	Vector2 AgentPos = An_Agent->GetPos();
	float Distance = AgentPos.dot(TargetPos);
	int SightRange = An_Agent->m_sightRange * An_Agent->m_sightRange;
	//~

	//Change state if the proper conditions are met
	if (Distance > An_Agent->m_attackRange)
		sm->ChangeState(An_Agent, CHASE);
	//~

	//Otherwise, move in chosen direction (continue to wander)
	else
	{
		//Decrease timer by DeltaTime, choose new direction when the timer is 0 or less
		m_timer -= DeltaTime;

		if (m_timer <= 0)
			SetDirection();
		//~

		An_Agent->AddForce(m_direction);
	}
	//~
}

void WanderState::Init(Agent* An_Agent)
{
	SetDirection();
}

void WanderState::Exit(Agent* An_Agent)
{

}


void WanderState::SetDirection()
{
	srand((unsigned int)time(NULL));
	int RandNum = rand() % 3;

	//Use RandNum to decide which direction the enemy should move in
	if (RandNum == 0)
		m_direction = Vector2(0,  100); //Up

	if (RandNum == 1)
		m_direction = Vector2(0, -100); //Down

	if (RandNum == 2)
		m_direction = Vector2(-100, 0); //Left

	else
		m_direction = Vector2( 100, 0); //Right
	//~

	m_timer = 4;
}