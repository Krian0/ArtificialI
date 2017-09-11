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

	m_behaviours.push_back(new SteeringBehaviour);
	m_behaviours.push_back(new KeyboardController);

	m_states.push_back(new AttackState);
	m_states.push_back(new WanderState);
	m_states.push_back(new ChaseState);
	m_states.push_back(new FleeState);

	m_enemySprite = new aie::Texture("./textures/ball_3.png");
	m_hitSprite = new aie::Texture("./textures/ball.png");

	m_player = new Player(m_behaviours, m_hitSprite, Vector2(500, 500));

	m_enemies.push_back(new Enemy(m_player, m_states, m_behaviours, m_enemySprite, m_hitSprite, Vector2(900, 500)));

	return true;
}

void Application2D::shutdown() 
{
	delete m_2dRenderer;
	delete m_enemySprite;
	delete m_hitSprite;

	while (m_enemies.size() > 0)
		m_enemies.pop_back();

	while (m_states.size() > 0)
		m_states.pop_back();

	while (m_behaviours.size() > 0)
		m_behaviours.pop_back();
}

void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;
	
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	m_player->FindClosestEnemy(m_enemies);
	m_player->Update(deltaTime);

	for (auto iter = m_enemies.begin(); iter != m_enemies.end(); iter++)
		(*iter)->Update(deltaTime);
}

void Application2D::draw() 
{
	clearScreen();
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);
	m_2dRenderer->begin();

	m_player->Draw(m_2dRenderer);

	for (auto iter = m_enemies.begin(); iter != m_enemies.end(); iter++)
		(*iter)->Draw(m_2dRenderer);

	m_2dRenderer->end();
}