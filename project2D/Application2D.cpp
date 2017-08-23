#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"


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

	m_states.push_back(new AttackState);
	m_states.push_back(new WanderState);
	m_states.push_back(new ChaseState);

	m_stateMap[ATTACK] = 0;
	m_stateMap[WANDER] = 1;
	m_stateMap[CHASE] = 2;

	return true;
}

void Application2D::shutdown() 
{
	delete m_2dRenderer;

	while (m_states.size > 0)
		m_states.pop_back();
}

void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;

	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() 
{
	clearScreen();
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);
	m_2dRenderer->begin();
	m_2dRenderer->end();
}