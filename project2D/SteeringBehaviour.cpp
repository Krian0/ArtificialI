#include "SteeringBehaviour.h"
#include "SteeringForce.h"
#include "BehaviourEnum.h"

SteeringBehaviour::SteeringBehaviour()
{
	m_steeringForce[SteeringE::KEYBOARD]	= nullptr;
	m_steeringForce[SteeringE::AVOID]		= nullptr;
	m_steeringForce[SteeringE::EVADE]		= nullptr;
	m_steeringForce[SteeringE::FLEE]		= nullptr;
	m_steeringForce[SteeringE::SEEK]		= nullptr;
	m_steeringForce[SteeringE::ARRIVAL]		= nullptr;
	m_steeringForce[SteeringE::WANDER]		= nullptr;
}

SteeringBehaviour::~SteeringBehaviour()
{
}


void SteeringBehaviour::Update(Agent* An_Agent, float DeltaTime)
{
	Vector2 Force(0, 0);

	for (unsigned int i = 0; i < m_steeringForce.size(); i++)
		if (m_steeringForce.at(SteeringE(i)) != nullptr)
			Force += m_steeringForce.at(SteeringE(i))->GetForce(An_Agent) * m_steeringForce.at(SteeringE(i))->GetWeight();

	An_Agent->AddForce(Force);
}

void SteeringBehaviour::AddSteering(SteeringE Steering_Enum, SteeringForce* Steering_Force)
{
	m_steeringForce.at(Steering_Enum) = Steering_Force;
}

void SteeringBehaviour::RemoveSteering(SteeringE Steering_Enum)
{
	m_steeringForce.at(Steering_Enum) = nullptr;
}