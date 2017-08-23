#pragma once
#include "Vector2.h"

class AABB_Cube;

class Circle
{

public:
#pragma region Circle Constructors + Destructor
	Circle();
	Circle(Vector2 MidPos, float Radius);
	Circle(const Vector2 *PointArray, int NumOfPoints);
	~Circle();
#pragma endregion


#pragma region Circle Set Functions
	//Set m_midPos from Vector parameter.
	void SetMidPos(Vector2 MidPos);
	//Set m_radius from float parameter.
	void SetRadius(float Radius);

	//Set all Circle variables from Vector2 parameter for MidPos, and a float parameter for Radius.
	void SetCircle(Vector2 MidPos, float Radius);
	//Set Circle to encompass an array of points. Parameters take a pointer to a Vector2 array and an int for the number of points.
	void SetCircle_FromPoints(const Vector2 *PointArray, int NumOfPoints);
#pragma endregion


#pragma region Circle Get Functions
	//Returns Vector2 m_midPos.
	Vector2 GetMidPos();
	//Returns float m_radius.
	float   GetRadius();
#pragma endregion


#pragma region Circle CheckOverlap Functions
	//Parameters take a Vector2 or Circle. Checks if Circle overlaps with shape of the parameters class. Returns true or false.
	bool CheckCircleOverlap(Vector2 Point);
	//Parameters take a Vector2 or Circle. Checks if Circle overlaps with shape of the parameters class. Returns true or false.
	bool CheckCircleOverlap(Circle _Circle);
#pragma endregion


private:
#pragma region Circle Variables
	Vector2 m_midPos;
	float m_radius;
#pragma endregion
};