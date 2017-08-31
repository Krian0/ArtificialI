#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "Vector2.h"
#include "Matrix2.h"

//
#include "AttackState.h"
#include "WanderState.h"
#include "ChaseState.h"
#include "Player.h"

class Application2D : public aie::Application 
{
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;

	float m_cameraX,	m_cameraY;
	float m_timer;

	aie::Texture* m_hitSprite;

	vector<State*>		m_states;
	map<StateEnum, int> m_stateMap;

	Player* m_player;
};