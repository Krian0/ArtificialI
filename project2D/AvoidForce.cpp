#include "AvoidForce.h"
#include "BoxObject.h"

AvoidForce::AvoidForce()
{
	m_weight = 8.00f;
}

AvoidForce::~AvoidForce()
{
}

Vector2 AvoidForce::GetForce(Agent* An_Agent)
{
	if (m_objects.size() == 0)
		m_objects = An_Agent->GetObjects();

	Vector2 V = An_Agent->GetCurrentVelocity();

	float DynamicLength = V.magnitude() / An_Agent->m_velocityLimit;

	Line Ahead(An_Agent->GetPos(), V.normalise(), DynamicLength * 120);

	BoxObject* ClosestObject = FindClosestObject(Ahead);
	Vector2 AvoidForce(0, 0);


	//Check EndPoint with Object
	if (ClosestObject->IsColliding(Ahead.m_endPoint) == true)
	{
		Vector2 COPos = ClosestObject->GetPos();
		AvoidForce = Ahead.m_endPoint - COPos;

		AvoidForce = AvoidForce.normalise() * (float)m_maxAvoidForce;
	}


	Ahead.m_endPoint2 = Ahead.m_endPoint / 2;
	
	//Check half-sized EndPoint with Object
	if (ClosestObject->IsColliding(Ahead.m_endPoint2) == true)
	{
		Vector2 COPos = ClosestObject->GetPos();
		AvoidForce = Ahead.m_endPoint2 - COPos;

		AvoidForce = AvoidForce.normalise() * (float)m_maxAvoidForce;
	}

	//Check Origin (current location) with Object
	if (ClosestObject->IsColliding(Ahead.m_origin) == true)
	{
		Vector2 COPos = ClosestObject->GetPos();
		AvoidForce = Ahead.m_origin - COPos;

		AvoidForce = AvoidForce.normalise() * (float)m_maxAvoidForce;
	}


	return AvoidForce;
}


BoxObject* AvoidForce::FindClosestObject(Line Ahead)
{
	BoxObject* ClosestObject;
	float LastDistance = 99999;

	for (auto Object : m_objects)
	{
		float CurrentDistance = (Ahead.m_origin - Object->GetPos()).magnitude();

		if (CurrentDistance < LastDistance)
		{
			ClosestObject = Object;
			LastDistance = CurrentDistance;
		}
	}

	return ClosestObject;
}