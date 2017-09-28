#pragma once
#include "Vector2.h"

struct Line
{
	Vector2 m_origin;
	Vector2 m_direction;

	float m_dynamicLength;
	Vector2 m_end;
	Vector2 m_endHalf;

	Line(Vector2 Origin, Vector2 Direction, float Length = 1) : m_origin(Origin), m_direction(Direction), m_dynamicLength(Length), m_end(Origin + Direction * Length) {}
};