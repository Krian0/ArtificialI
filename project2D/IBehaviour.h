#pragma once
#include "BehaviourEnum.h"

class Agent;

class IBehaviour
{

public:
	IBehaviour() {}
	virtual ~IBehaviour() {}

	virtual void Update(Agent* An_Agent, float DeltaTime) = 0;

private:

};