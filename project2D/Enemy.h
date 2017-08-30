#pragma once
#include "Agent.h"

class Enemy : public Agent
{
public:
	Enemy(Agent* Target, vector<State*> Available_States, map<StateEnum, int> State_Map, aie::Texture* Sprite, aie::Texture* Hit_Sprite);
	~Enemy();

	void Update(float DeltaTime) override;
	void Draw(aie::Renderer2D* renderer) override;

private:

};