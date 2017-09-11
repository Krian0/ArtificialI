#include "KeyboardForce.h"

KeyboardForce::KeyboardForce()
{
}

KeyboardForce::~KeyboardForce()
{
}

Vector2 KeyboardForce::GetForce(Agent* An_Agent)
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


	//Add corresponding direction value to movement vector
	Vector2 Force(0, 0);

	if (up == true && down == false)
		Force.y = 100;

	if (down == true && up == false)
		Force.y = -100;

	if (left == true && right == false)
		Force.x = -100;

	if (right == true && left == false)
		Force.x = 100;
	//~

	return Force;
}