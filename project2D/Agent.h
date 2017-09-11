#pragma once
#include "Vector2.h"
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
	void OnFlee();

	//Returns variable matching the function name
	Agent*	GetTarget();
	Vector2	GetTargetPos();
	Vector2	GetPos();
	Vector2 GetCurrentVelocity();

	float	GetRadius();
	bool	WasAttacked();
	bool	HasHitWall();
	bool	Collision(Agent* The_Target);
	//~

	int m_sightRange;
	int m_attackRange;
	int m_velocityLimit;

protected:

	//Body
	Texture* m_sprite;
	Texture* m_hitSprite;

	Vector2 m_position;
	Vector2 m_force;
	Vector2 m_velocity;

	float	m_radius;

	//Brain
	Agent*	m_target;

	bool	m_wasAttacked;
	bool	m_hitWall;
	bool	m_firstRound;
	int		m_flickerCounter;
	float	m_flickerTime;

private:

};