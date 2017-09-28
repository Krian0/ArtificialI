#pragma once
class Agent;

class IBehaviour
{

public:
	IBehaviour() {}
	virtual ~IBehaviour() {}

	//Updates Behaviour. Takes an Agent* and a float as parameters
	virtual void Update(Agent* An_Agent, float DeltaTime) = 0;
};