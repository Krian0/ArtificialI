#pragma once
#include "IBehaviour.h"

class KeyboardController : IBehaviour
{
public:
	KeyboardController();
	~KeyboardController();

	void Update(Player* The_Player) override;
	
private:

};