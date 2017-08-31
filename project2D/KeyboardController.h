#pragma once
#include "IBehaviour.h"
#include "Input.h"

class KeyboardController : public IBehaviour
{
public:
	KeyboardController();
	~KeyboardController();

	void Update(Agent* The_Player) override;
	
private:

};