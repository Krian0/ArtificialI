#include "Circle.h"

#pragma region Circle Constructors + Destructor
//Don't use the default
Circle::Circle()
{
}

Circle::Circle(Vector2 MidPos, float Radius)
{
	SetCircle(MidPos, Radius);
}

Circle::Circle(const Vector2 *PointArray, int NumOfPoints)
{
	SetCircle_FromPoints(PointArray, NumOfPoints);
}

Circle::~Circle()
{
}
#pragma endregion


#pragma region Circle Set Functions
void Circle::SetMidPos(Vector2 MidPos)
{
	m_midPos = MidPos;
}

void Circle::SetRadius(float Radius)
{
	m_radius = Radius;
}

void Circle::SetCircle(Vector2 MidPos, float Radius)
{
	m_midPos = MidPos;
	m_radius = Radius;
}

void Circle::SetCircle_FromPoints(const Vector2 *PointArray, int NumOfPoints)
{
	if (NumOfPoints > 1)
	{
		Vector2 _Min(INFINITY, INFINITY);
		Vector2 _Max(-INFINITY, -INFINITY);

		for (int i = 0; i < NumOfPoints; i++)
		{
			if (PointArray[i].x < _Min.x)
				_Min.x = PointArray[i].x;

			if (PointArray[i].y < _Min.y)
				_Min.y = PointArray[i].y;

			if (PointArray[i].x > _Max.x)
				_Max.x = PointArray[i].x;

			if (PointArray[i].y > _Max.y)
				_Max.y = PointArray[i].y;
		}

		m_midPos = (_Min + ((_Max - _Min) / 2));

		//Iterates through each point in PointArray to find which is the furthest away.
		float LastDistance = -INFINITY;
		for (int i = 0; i < NumOfPoints; i++)
		{
			Vector2 Temp = PointArray[i];
			if (m_midPos.dot(Temp) > LastDistance)
				LastDistance = m_midPos.dot(Temp);
		}
		//~

		//Sets Radius to square root of the Largest Distance.
		m_radius = sqrt(LastDistance);
		//~
	}
}
#pragma endregion


#pragma region Circle Get Functions
Vector2 Circle::GetMidPos()
{
	return m_midPos;
}

float Circle::GetRadius()
{
	return m_radius;
}
#pragma endregion


#pragma region Circle CheckOverlap Functions
bool Circle::CheckCircleOverlap(Vector2 Point)
{
	bool IsThereAnOverlap = false;

	if (m_midPos.dot(Point) <= (m_radius * m_radius))
		IsThereAnOverlap = true;

	return IsThereAnOverlap;
}

bool Circle::CheckCircleOverlap(Circle _Circle)
{
	float CombinedRadiiSquared = (m_radius + _Circle.m_radius) * (m_radius + _Circle.m_radius);
	bool IsThereAnOverlap = false;

	if (m_midPos.dot(_Circle.m_midPos) <= CombinedRadiiSquared)
		IsThereAnOverlap = true;

	return IsThereAnOverlap;
}
#pragma endregion