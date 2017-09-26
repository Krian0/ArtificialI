#pragma once
#include "Agent.h"
#include "SteeringBehaviour.h"

class AStarGraph;

class Enemy : public Agent
{
public:
	Enemy(Agent* Target, Texture* Sprite, Texture* Hit_Sprite, Vector2 Position, AStarGraph* Graph);
	~Enemy();

	void Update(float DeltaTime) override;
	void Draw(Renderer2D* renderer) override;


private:

	AStarGraph*	m_pathfinding;

};