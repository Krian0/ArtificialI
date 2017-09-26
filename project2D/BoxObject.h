#pragma once
#include "Vector2.h"
#include "Texture.h"
#include "Renderer2D.h"

class Agent;

class BoxObject
{
public:
	BoxObject(Vector2 MidPos, Vector2 HalfSize);
	~BoxObject();

	void Draw(aie::Renderer2D* renderer);

	bool IsColliding(Vector2 Point);
	bool IsColliding(Agent* An_Agent);
	Vector2 GetPos();
	Vector2 GetMin();
	Vector2 GetMax();
	Vector2 GetHalf();

private:

	Vector2 m_min;
	Vector2 m_max;

	Vector2 m_pos;
	Vector2 m_half;

	aie::Texture* m_sprite;

};