#pragma once
#include "SteeringForce.h"
#include <stack>
using std::stack;

class SeekForce : public SteeringForce
{
public:
	SeekForce();
	~SeekForce();

	Vector2 GetForce(Agent* An_Agent) override;

private:

	stack<Vector2> m_pathfindingTargets;

};