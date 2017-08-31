#pragma once
#include "Circle.h"
#include "Texture.h"
#include "Renderer2D.h"
using aie::Texture;
using aie::Renderer2D;

class Agent
{

public:
	Agent() {}
	~Agent() {};

	virtual void Update(float DeltaTime) = 0;
	virtual void Draw(Renderer2D* renderer) = 0;

	//Sets m_force to the Vector2 parameter
	void AddForce(Vector2 force);
	//Makes the Agent's sprite flicker to a hit-sprite and back several times upon being hit
	void OnHit();

	//Returns variable matching the function name
	Vector2	GetPos();
	Vector2	GetTargetPos();
	Agent*	GetTarget();
	Circle	GetCollider();
	//~

	const int m_sightRange = 250;
	const int m_attackRange = 80;

protected:

	int		m_flickerCounter;
	float	m_flickerTime;
	bool	m_firstRound;


	//
	Circle m_collider;

	Texture* m_sprite;
	Texture* m_hitSprite;

	Vector2 m_force;
	Vector2 m_velocity;

	//
	Agent* m_target;

private:

};