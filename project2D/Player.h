#pragma once
#include "KeyboardController.h"
#include <vector>
using std::vector;

class Player : public Agent
{
public:
	Player(Agent* Target, Texture* Hit_Sprite, Vector2 Position, float Radius);
	~Player();

	void Update(float DeltaTime) override;
	void Draw(Renderer2D* renderer) override;

private:

	vector<IBehaviour*> m_behaviours;

	int m_velocityLimit = 500;

};