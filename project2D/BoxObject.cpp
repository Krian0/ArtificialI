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
	renderer->setRenderColour(0, 0, 1, 0.500f);
	renderer->drawBox(m_pos.x, m_pos.y, m_half.x * 2, m_half.y * 2);
	renderer->setRenderColour(1, 1, 1);
}


bool BoxObject::IsColliding(Vector2 Point)
{
	return (m_min.x < Point.x && m_min.y < Point.y && m_max.x > Point.x && m_max.y > Point.y);
}

bool BoxObject::IsColliding(Vector2 Point, float Radius)
{
	Vector2 Result;
	Result.x = Point.x - max(m_pos.x - m_half.x, min(Point.x, m_pos.x + m_half.x));
	Result.y = Point.y - max(m_pos.y - m_half.y, min(Point.y, m_pos.y + m_half.y));

	if ((Result.x * Result.x + Result.y * Result.y) < (Radius * Radius))
		return true;

	return false;
}

bool BoxObject::IsColliding(Agent* An_Agent)
{
	return IsColliding(An_Agent->GetPos(), An_Agent->GetRadius());
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