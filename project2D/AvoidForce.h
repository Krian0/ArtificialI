#pragma once
#include "SteeringForce.h"

class BoxObject;
struct Line;

class AvoidForce : public SteeringForce
{
public:
	AvoidForce();
	~AvoidForce();

	Vector2 GetForce(Agent* An_Agent) override;

private:

	BoxObject* FindClosestObject(Line Ahead);

	const int m_maxSight = 120;
	const int m_maxAvoidForce = 640;
	
	vector<BoxObject*> m_objects;

};

struct Line
{
	Vector2 m_origin;
	Vector2 m_direction;

	float m_dynamicLength;
	Vector2 m_endPoint;
	Vector2 m_endPoint2;

	Line(Vector2 Origin, Vector2 Direction, float Length = 1) : m_origin(Origin), m_direction(Direction), m_dynamicLength(Length), m_endPoint(Origin + Direction * Length) {}
};