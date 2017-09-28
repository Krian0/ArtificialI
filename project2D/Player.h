#pragma once
#include "Agent.h"

class Player : public Agent
{
public:
	Player(Texture* Hit_Sprite, Vector2 Position, Vector2 WindowSize);
	~Player();

	//Updates StateMachine, Behaviour, movement, collision and Sprite related timer. Takes a float as parameter
	void Update(float DeltaTime) override;
	//Renders the Player, any pathfinding positions being sought, and sets some Sprite related variables. Takes a Renderer2D* as parameter
	void Draw(Renderer2D* renderer) override;
};