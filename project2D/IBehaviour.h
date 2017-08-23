#pragma once
#include "Player.h"

class IBehaviour
{

public:
	IBehaviour() {}
	virtual ~IBehaviour() {}

	virtual void Update(Player* The_Player) = 0;

private:

};