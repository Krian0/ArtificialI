#pragma once
#include "Renderer2D.h"
#include "Vector2.h"

class Agent;

class BoxObject
{
public:
	BoxObject(Vector2 MidPos, Vector2 HalfSize);
	~BoxObject();

	//Draw the BoxObject. Takes a Renderer2D* as parameter
	void Draw(aie::Renderer2D* renderer);

	//Returns true if the given Vector2 intersects with the BoxObject, otherwise returns false. Takes a Vector2 as parameter
	bool IsColliding(Vector2 Point);
	
	//Returns true if the given Vector2 and float (circle) intersects with the BoxObject, otherwise returns false. Takes a Vector2 and float as parameters
	bool IsColliding(Vector2 Point, float Radius);

	//Returns true if the given Agent* intersects with the BoxObject, otherwise returns false. Takes an Agent* as parameter
	bool IsColliding(Agent* An_Agent);
	
	//Return Vector2 m_pos
	Vector2 GetPos();
	
	//Return Vector2 m_min
	Vector2 GetMin();
	
	//Return Vector2 m_max
	Vector2 GetMax();
	
	//Return Vector2 m_half
	Vector2 GetHalf();

private:

	Vector2 m_min;
	Vector2 m_max;

	Vector2 m_pos;
	Vector2 m_half;
};