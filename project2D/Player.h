#pragma once
#include "Agent.h"

class Player : public Agent
{
public:
	Player(Agent* Target, aie::Texture* Hit_Sprite);
	~Player();

	void Update(float DeltaTime) override;
	void Draw(aie::Renderer2D* renderer) override;

private:

};