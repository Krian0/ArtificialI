#include "AvoidForce.h"
#include "LineStruct.h"
#include "BoxObject.h"

AvoidForce::AvoidForce()
{
	m_weight = 6.00f;
}

AvoidForce::~AvoidForce()
{
}

Vector2 AvoidForce::GetForce(Agent* An_Agent)
{
	if (m_objects.size() == 0)
		m_objects = An_Agent->GetObjects();

	Vector2 V = An_Agent->GetCurrentVelocity();

	float Length = 40;

	//Calculate end and endHalf
	Line Ahead(An_Agent->GetPos(), V.normalise(), Length);
	Ahead.m_endHalf = Ahead.m_end * 0.5;

	//Find closest Object
	BoxObject* ClosestObject = FindClosestObject(Ahead, An_Agent->GetRadius());
	Vector2 AvoidForce(0, 0);


	if (ClosestObject != nullptr) 
	{
		AvoidForce = Ahead.m_end - ClosestObject->GetPos();
		AvoidForce = AvoidForce.normalise();
		AvoidForce *= (float)m_maxAvoidForce;
	}

	else 
		AvoidForce *= 0;


	return AvoidForce;
}


BoxObject* AvoidForce::FindClosestObject(Line Ahead, float Radius)
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

	if (ClosestObject->IsColliding(Ahead.m_origin, Radius +2) || ClosestObject->IsColliding(Ahead.m_end, Radius +2) || 
		ClosestObject->IsColliding(Ahead.m_endHalf, Radius +2))
		return ClosestObject;

	return nullptr;
}