#pragma once
#include "StateMachine.h"
#include "Vector2.h"
#include "Circle.h"
#include "Agent.h"
#include <vector>
using std::vector;

struct EntityFrame
{
	float radius;

	Circle collider;

	Vector2 position;
	Vector2 force;
	Vector2 velocity;
};

struct EntityBrain
{
	Agent* target;
	vector<IBehaviour*> behaviours;
	
	StateMachine *stateMachine;
};