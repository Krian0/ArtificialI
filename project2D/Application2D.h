#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "Font.h"

#include "AStarStructs.h"
#include "AStarGraph.h"
#include "BoxObject.h"
#include "Player.h"
#include "Enemy.h"


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

	aie::Texture* m_enemySprite;
	aie::Texture* m_hitSprite;

	aie::Font* m_font;

	AStarGraph*		m_pathfinding;

	vector<BoxObject*>	m_objects;
	Player*				m_player;
	vector<Agent*>		m_enemies;

	bool m_switchToPathfinding;
	float m_switchTimer = 2;
};