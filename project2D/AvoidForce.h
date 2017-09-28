#pragma once
#include "SteeringForce.h"
#include <vector>
using std::vector;

struct Line;

class BoxObject;

class AvoidForce : public SteeringForce
{
public:
	AvoidForce();
	~AvoidForce();

	//Returns a Vector2 Force that moves the given Agent* away from Objects. Takes an Agent* as parameter
	Vector2 GetForce(Agent* An_Agent) override;

private:

	//Returns the BoxObject* that is closest to the Agent if it passes a collision check, otherwise returns nullptr. Takes a Line and float as parameters
	BoxObject* FindClosestObject(Line Ahead, float Radius);


	vector<BoxObject*> m_objects;
	
	const int m_maxAvoidForce = 4000;
};