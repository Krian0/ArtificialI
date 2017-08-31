#pragma once
#include "StateMachine.h"

class Enemy : public Agent
{
public:
	Enemy(Agent* Target, vector<State*> States, map<StateEnum, int> State_Map, Texture* Sprite, Texture* Hit_Sprite, Vector2 Position, float Radius);
	~Enemy();

	void Update(float DeltaTime) override;
	void Draw(aie::Renderer2D* renderer) override;

private:

	StateMachine* m_stateMachine;

	int m_velocityLimit = 480;

};