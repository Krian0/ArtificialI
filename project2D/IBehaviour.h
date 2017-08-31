#pragma once
#include "Agent.h"

class IBehaviour
{

public:
	IBehaviour() {}
	virtual ~IBehaviour() {}

	virtual void Update(Agent* The_Player) = 0;

private:

};