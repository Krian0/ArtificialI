#pragma once
#include "Agent.h"

class Enemy : public Agent
{
public:
	Enemy(vector<State*> Available_States, map<StateEnum, int> State_Map, Agent* The_Player);
	~Enemy();

	void Update(float DeltaTime) override;
	void Draw(aie::Renderer2D* renderer) override;

private:

};