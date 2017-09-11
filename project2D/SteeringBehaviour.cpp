#include "SteeringBehaviour.h"

SteeringBehaviour::SteeringBehaviour()
{
}

SteeringBehaviour::~SteeringBehaviour()
{
}


void SteeringBehaviour::Update(Agent* An_Agent, float DeltaTime)
{
	An_Agent->AddForce(m_steeringForce->GetForce(An_Agent));
}