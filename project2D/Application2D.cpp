#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <time.h>

Application2D::Application2D() {}

Application2D::~Application2D() {}

bool Application2D::startup() 
{
	m_2dRenderer = new aie::Renderer2D();

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	srand((unsigned int)time(NULL));
	Vector2 WS((float)getWindowWidth(), (float)getWindowHeight());

	m_switchToPathfinding = false;
	m_pathfinding = new AStarGraph();


	m_enemySprite = new aie::Texture("./textures/ball_3.png");
	m_hitSprite = new aie::Texture("./textures/ball.png");
	m_font = new aie::Font("./font/consolas_italic.ttf", 18);


	m_objects.push_back(new BoxObject(Vector2(514, 474), Vector2(200, 40)));
	m_objects.push_back(new BoxObject(Vector2(828, 320), Vector2(100, 20)));
	m_objects.push_back(new BoxObject(Vector2(196, 110), Vector2(100, 20)));
	m_pathfinding->SetGraphNodes(10, 10, m_objects, WS);

	m_player = new Player(m_hitSprite, Vector2(200, 200), WS);
	m_enemies.push_back(new Enemy(m_player, m_enemySprite, m_hitSprite, Vector2(900, 700), WS, m_pathfinding));
	m_enemies.push_back(new Enemy(m_player, m_enemySprite, m_hitSprite, Vector2(900, 600), WS, m_pathfinding));
	m_enemies.push_back(new Enemy(m_player, m_enemySprite, m_hitSprite, Vector2(900, 500), WS, m_pathfinding));


	m_player->SetTargetList(m_enemies);
	m_player->AddObjects(m_objects);

	for (unsigned int i = 0; i < m_enemies.size(); i++)
	{
		for (unsigned int e = 0; e < m_enemies.size(); e++)
			if (e != i)
				m_enemies[i]->AddFriendToList(m_enemies[e]);

		m_enemies[i]->AddObjects(m_objects);
	}


	return true;
}

void Application2D::shutdown() 
{
	delete m_2dRenderer;
	delete m_pathfinding;
	delete m_enemySprite;
	delete m_hitSprite;
	delete m_font;
	m_objects.clear();
	delete m_player;
	m_enemies.clear();
}

void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;
	if (m_switchTimer > -2)
		m_switchTimer -= deltaTime;
	

	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	if (input->isKeyDown(aie::INPUT_KEY_E) && m_switchTimer <= 0)
	{
		
		m_switchTimer = 2;
		m_switchToPathfinding = !m_switchToPathfinding;

		for (auto EN : m_enemies)
		{
			EN->SetPathfindingMode(m_switchToPathfinding);
		}
	}


	m_player->Update(deltaTime);

	for (auto EN : m_enemies)
		EN->Update(deltaTime);
}

void Application2D::draw() 
{
	clearScreen();
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);
	m_2dRenderer->begin();


	if (m_switchToPathfinding == true)
		for (auto N : m_pathfinding->m_nodes)
			m_2dRenderer->drawCircle(N->m_position.x, N->m_position.y, 6);

	m_2dRenderer->setRenderColour(1, 0, 1, 0.4);
	if (m_switchTimer <= 0)
		m_2dRenderer->drawText(m_font, "Press E to switch to Pathfinding Mode", 640, 700);
	m_2dRenderer->setRenderColour(1, 1, 1);

	for (auto OB : m_objects)
		OB->Draw(m_2dRenderer);

	m_player->Draw(m_2dRenderer);

	for (auto EN : m_enemies)
		EN->Draw(m_2dRenderer);


	m_2dRenderer->end();
}