#pragma once
#include "Agent.h"
#include "SteeringBehaviour.h"
#include <vector>
using std::vector;

class Player : public Agent
{
public:
	Player(Texture* Hit_Sprite, Vector2 Position);
	~Player();

	void Update(float DeltaTime) override;
	void Draw(Renderer2D* renderer) override;

	

private:

};