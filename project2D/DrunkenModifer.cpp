#include "DrunkenModifer.h"
#include "Input.h"

DrunkenModifier::DrunkenModifier()
{
}

DrunkenModifier::~DrunkenModifier()
{
}

void DrunkenModifier::Update(Player* The_Player)
{
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_UP))
		The_Player->AddForce(Vector2(0, 1));

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		The_Player->AddForce(Vector2(0, -1));

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		The_Player->AddForce(Vector2(1, 0));

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		The_Player->AddForce(Vector2(-1, 0));
}