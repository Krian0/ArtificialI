#pragma once
#include "Agent.h"
#include "KeyboardController.h"
#include <vector>
using std::vector;

class Player : public Agent
{
public:
	Player(vector<IBehaviour*> Behaviours, Texture* Hit_Sprite, Vector2 Position);
	~Player();

	void Update(float DeltaTime) override;
	void Draw(Renderer2D* renderer) override;

	void FindClosestEnemy(vector<Agent*> Enemies);

private:

	vector<Agent*> m_enemyList;

};