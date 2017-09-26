#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

//


Application2D::Application2D() 
{
}

Application2D::~Application2D() 
{
}

bool Application2D::startup() 
{
	m_2dRenderer = new aie::Renderer2D();

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;


	m_switchToPathfinding = false;
	m_pathfinding = new AStarGraph();
	m_pathfinding->SetGraphNodes(20, 20);


	m_enemySprite = new aie::Texture("./textures/ball_3.png");
	m_hitSprite = new aie::Texture("./textures/ball.png");


	m_objects.push_back(new BoxObject(Vector2(500, 500), Vector2(200, 40)));
	m_objects.push_back(new BoxObject(Vector2(800, 300), Vector2(100, 20)));
	m_objects.push_back(new BoxObject(Vector2(200, 100), Vector2(100, 20)));

	m_player = new Player(m_hitSprite, Vector2(200, 200));
	m_enemies.push_back(new Enemy(m_player, m_enemySprite, m_hitSprite, Vector2(900, 700), m_pathfinding));
	m_enemies.push_back(new Enemy(m_player, m_enemySprite, m_hitSprite, Vector2(900, 600), m_pathfinding));
	m_enemies.push_back(new Enemy(m_player, m_enemySprite, m_hitSprite, Vector2(900, 500), m_pathfinding));
	m_enemies.push_back(new Enemy(m_player, m_enemySprite, m_hitSprite, Vector2(800, 700), m_pathfinding));
	m_enemies.push_back(new Enemy(m_player, m_enemySprite, m_hitSprite, Vector2(800, 600), m_pathfinding));
	m_enemies.push_back(new Enemy(m_player, m_enemySprite, m_hitSprite, Vector2(800, 500), m_pathfinding));


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
	delete m_player;
	m_objects.clear();
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
			EN->SetPathfindingMode(m_switchToPathfinding);
	}


	m_player->Update(deltaTime);

	for (auto iter = m_enemies.begin(); iter != m_enemies.end(); iter++)
		(*iter)->Update(deltaTime);
}

void Application2D::draw() 
{
	clearScreen();
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);
	m_2dRenderer->begin();


	if (m_switchToPathfinding == true)
		for (auto Nodes : m_pathfinding->m_nodes)
			m_2dRenderer->drawCircle(Nodes->m_position.x, Nodes->m_position.y, 6);


	m_player->Draw(m_2dRenderer);

	for (auto An_Enemy : m_enemies)
		An_Enemy->Draw(m_2dRenderer);

	for (auto Object : m_objects)
		Object->Draw(m_2dRenderer);


	m_2dRenderer->end();
}