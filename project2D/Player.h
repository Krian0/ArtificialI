#pragma once
#include "Agent.h"

class Player : public Agent
{
public:
	Player(Agent* Enemy_Target);
	~Player();

	void Update(float DeltaTime) override;
	void Draw(aie::Renderer2D* renderer) override;

private:

};