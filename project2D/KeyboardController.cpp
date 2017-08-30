#include "KeyboardController.h"
#include "Input.h"

KeyboardController::KeyboardController()
{
}

KeyboardController::~KeyboardController()
{
}

void KeyboardController::Update(Player* The_Player)
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


	//Detect pressed action keys and call matching function
	if (input->isKeyDown(aie::INPUT_KEY_SPACE))
		The_Player->OnHit();
	//~


	//Add corresponding direction value to movement vector
	Vector2 Vec(0, 0);

	if (up == true && down == false)
		Vec.y = 1;

	if (down == true && up == false)
		Vec.y = -1;

	if (left == true && right == false)
		Vec.x = 1;

	if (right == true && left == false)
		Vec.x = -1;
	//~

	The_Player->AddForce(Vec);
}