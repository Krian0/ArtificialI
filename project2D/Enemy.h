#pragma once
#include "Agent.h"

class Enemy : public Agent
{
public:
	Enemy(Agent* Target, vector<State*> States, vector<IBehaviour*> Behaviours, Texture* Sprite, Texture* Hit_Sprite, Vector2 Position);
	~Enemy();

	void Update(float DeltaTime) override;
	void Draw(aie::Renderer2D* renderer) override;

private:

};