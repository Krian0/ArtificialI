#include "KeyboardController.h"
#include "Agent.h"

KeyboardController::KeyboardController()
{
}

KeyboardController::~KeyboardController()
{
}

void KeyboardController::Update(Agent* An_Agent, float DeltaTime)
{
	aie::Input* input = aie::Input::getInstance();


	//Detect pressed action keys and call matching function if conditions are met
	if (input->isKeyDown(aie::INPUT_KEY_SPACE))
	{
		if (An_Agent->GetTarget() != NULL)
		{
			Vector2 TargetPos = An_Agent->GetTargetPos();
			Vector2 Pos = TargetPos - An_Agent->GetPos();

			float TargetRadius = An_Agent->GetTarget()->GetRadius();
			float CombinedRadiiSquared = (An_Agent->m_attackRange + TargetRadius) * (An_Agent->m_attackRange + TargetRadius);
			
			if (Pos.dot(Pos) <= CombinedRadiiSquared)
				An_Agent->GetTarget()->OnHit();
		}
	}
	//~
}