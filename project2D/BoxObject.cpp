#include "BoxObject.h"
#include "Agent.h"
#include <algorithm>
using std::min;
using std::max;

BoxObject::BoxObject(Vector2 MidPos, Vector2 HalfSize)
{
	m_min = (MidPos - HalfSize);
	m_max = (MidPos + HalfSize);

	m_pos = MidPos;
	m_half = HalfSize;
}

BoxObject::~BoxObject()
{
}


void BoxObject::Draw(aie::Renderer2D* renderer)
{
	renderer->drawBox(m_pos.x, m_pos.y, m_half.x * 2, m_half.y * 2);
}


bool BoxObject::IsColliding(Vector2 Point)
{
	bool IsThereAnOverlap = false;
	if (m_min.x < Point.x && m_min.y < Point.y && m_max.x > Point.x && m_max.y > Point.y)
		IsThereAnOverlap = true;

	return IsThereAnOverlap;
}

bool BoxObject::IsColliding(Agent* An_Agent)
{
	float Radius = An_Agent->GetRadius();
	Vector2 Pos = An_Agent->GetPos();
	
	Vector2 Result;
	Result.x = Pos.x - max(m_pos.x - m_half.x, min(Pos.x, m_pos.x + m_half.x));
	Result.y = Pos.y - max(m_pos.y - m_half.y, min(Pos.y, m_pos.y + m_half.y));
	
	return (Result.x * Result.x + Result.y * Result.y) < (Radius * Radius);
}

Vector2 BoxObject::GetPos()
{
	return m_pos;
}

Vector2 BoxObject::GetMin()
{
	return m_min;
}

Vector2 BoxObject::GetMax()
{
	return m_max;
}

Vector2 BoxObject::GetHalf()
{
	return m_half;
}