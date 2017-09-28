#pragma once
#include "Agent.h"

class Enemy : public Agent
{
public:
	Enemy(Agent* Target, Texture* Sprite, Texture* Hit_Sprite, Vector2 Position, Vector2 WindowSize, AStarGraph* Graph);
	~Enemy();

	//Updates StateMachine, Behaviour, movement, collision and Sprite related timer. Takes a float as parameter
	void Update(float DeltaTime) override;
	//Renders the Enemy, any pathfinding positions being sought, and sets some Sprite related variables. Takes a Renderer2D* as parameter
	void Draw(Renderer2D* renderer) override;
};