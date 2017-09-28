#pragma once
#include "SteeringForce.h"
#include <stack>
using std::stack;

class SeekForce : public SteeringForce
{
public:
	SeekForce();
	~SeekForce();

	//Returns a Vector2 Force that moves the given Agent* towards either the Player or a Node. Takes an Agent* as parameter
	Vector2 GetForce(Agent* An_Agent) override;

private:

	stack<Vector2> m_pathfindingTargets;
};