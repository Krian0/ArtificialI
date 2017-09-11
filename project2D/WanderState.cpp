#include "WanderState.h"

void WanderState::Update(Agent* An_Agent, StateMachine* sm, float DeltaTime)
{
	//Work out the distance from Enemy to Player
	float Distance = (An_Agent->GetPos() - An_Agent->GetTargetPos()).magnitude();
	//~

	//Change state if the proper conditions are met
	if (Distance <= An_Agent->m_sightRange)
	{
		sm->ChangeState(An_Agent, CHASE);
		return;
	}
	//~

	//Otherwise, move in chosen direction (continue to wander)
	else
	{
		//Decrease timer by DeltaTime, choose new direction when the timer is 0 or less
		m_timer -= DeltaTime;

		if (m_timer <= 0 || An_Agent->HasHitWall() == true)
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
	int x = 0;
	int y = 0;

	while (x <= 4 || y <= 14)
	{
		x = rand() % 10;
		y = rand() % 20 + 10;
	}

	int RandNum = rand() % 3;

	//Use RandNum to decide which direction the Enemy should move in
	if (x > 4)
	{
		if (RandNum == 0)
			m_direction = Vector2(0, 100); //Up

		if (RandNum == 1)
			m_direction = Vector2(0, -100); //Down
	}

	if (y > 14)
	{
		if (RandNum == 2)
			m_direction = Vector2(-100, 0); //Left

		if (RandNum == 3)
			m_direction = Vector2(100, 0); //Right
	}
	//~

	m_timer = 0.2;
}