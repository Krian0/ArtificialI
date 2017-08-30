#pragma once
#include "EntityStructs.h"
#include "Renderer2D.h"

class Agent
{

public:
	Agent() {}
	virtual ~Agent() = 0;

	virtual void Update(float DeltaTime) = 0;
	virtual void Draw(aie::Renderer2D* renderer) = 0;

	void AddForce(Vector2 force);
	void OnHit();

	Vector2	GetPos();
	Vector2	GetTargetPos();
	Agent*	GetTarget();
	Circle	GetCollider();

	int m_sightRange = 100;
	int m_attackRange = 80;
	int m_velocityLimit = 100;

protected:

	EntityFrame m_frame;
	EntityBrain m_brain;

	int		m_flickerCounter;
	float	m_flickerTime;
	bool	m_firstRound;

private:

};