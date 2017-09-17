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

	m_states[StateE::ATTACK]	= new AttackState;
	m_states[StateE::WANDER]	= new WanderState;
	m_states[StateE::CHASE]		= new ChaseState;
	m_states[StateE::FLEE]		= new FleeState;

	m_enemySprite = new aie::Texture("./textures/ball_3.png");
	m_hitSprite = new aie::Texture("./textures/ball.png");

	m_player = new Player(m_states, m_hitSprite, Vector2(500, 500));
	m_enemies.push_back(new Enemy(m_player, m_states, m_enemySprite, m_hitSprite, Vector2(900, 500)));

	m_player->SetTargetList(m_enemies);

	return true;
}

void Application2D::shutdown() 
{
	delete m_2dRenderer;
	delete m_enemySprite;
	delete m_hitSprite;

	delete m_player;
	m_enemies.clear();

	m_states.clear();
}

void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;
	
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

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