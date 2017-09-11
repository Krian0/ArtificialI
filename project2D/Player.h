#pragma once
#include "KeyboardController.h"
#include <vector>
using std::vector;

class Player : public Agent
{
public:
	Player(Texture* Hit_Sprite, Vector2 Position, float Radius);
	~Player();

	void Update(float DeltaTime) override;
	void Draw(Renderer2D* renderer) override;

	void FindClosestEnemy(vector<Agent*> Enemies);

private:

	vector<IBehaviour*> m_behaviours;
	vector<Agent*> m_enemyList;

};