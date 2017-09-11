#include "KeyboardController.h"

KeyboardController::KeyboardController()
{
}

KeyboardController::~KeyboardController()
{
}

void KeyboardController::Update(Agent* An_Agent, float DeltaTime)
{
	aie::Input* input = aie::Input::getInstance();
	bool up = false, down = false, left = false, right = false;


	//Detect pressed direction keys
	if (input->isKeyDown(aie::INPUT_KEY_UP))
		up = true;

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		down = true;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		left = true;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		right = true;
	//~


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


	//Add corresponding direction value to movement vector
	Vector2 Vec(0, 0);

	if (up == true && down == false)
		Vec.y = 100;

	if (down == true && up == false)
		Vec.y = -100;

	if (left == true && right == false)
		Vec.x = -100;

	if (right == true && left == false)
		Vec.x = 100;
	//~

	An_Agent->AddForce(Vec);
}