#include "SteeringBehaviour.h"

SteeringBehaviour::SteeringBehaviour()
{
	m_steeringForce[SteeringE::KEYBOARD]	= NULL;
	m_steeringForce[SteeringE::EVADE]		= NULL;
	m_steeringForce[SteeringE::FLEE]		= NULL;
	m_steeringForce[SteeringE::SEEK]		= NULL;
	m_steeringForce[SteeringE::ARRIVAL]		= NULL;
	m_steeringForce[SteeringE::WANDER]		= NULL;
}

SteeringBehaviour::~SteeringBehaviour()
{
}


void SteeringBehaviour::Update(Agent* An_Agent, float DeltaTime)
{
	Vector2 Force(0, 0);

	for (unsigned int i = 0; i < m_steeringForce.size(); i++)
		if (m_steeringForce.at(SteeringE(i)) != NULL)
			Force += m_steeringForce.at(SteeringE(i))->GetForce(An_Agent) * m_steeringForce.at(SteeringE(i))->GetWeight();

	An_Agent->AddForce(Force);
}

void SteeringBehaviour::AddSteering(SteeringE Steering_Enum, SteeringForce* Steering_Force)
{
	m_steeringForce.at(Steering_Enum) = Steering_Force;
}

void SteeringBehaviour::RemoveSteering(SteeringE Steering_Enum)
{
	m_steeringForce.at(Steering_Enum) = NULL;
}