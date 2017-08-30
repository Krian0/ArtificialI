#pragma once
#include "StateMachine.h"
#include "IBehaviour.h"
#include "Texture.h"
#include "Vector2.h"
#include "Circle.h"
#include "Agent.h"
#include <vector>
using std::vector;

struct EntityFrame
{
	Circle collider;

	aie::Texture* m_sprite;
	aie::Texture* m_hitSprite;

	Vector2 force;
	Vector2 velocity;
};

struct EntityBrain
{
	Agent* target;
	
	vector<IBehaviour*> behaviours;
	StateMachine *stateMachine;
};