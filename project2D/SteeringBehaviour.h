#pragma once
#include "IBehaviour.h"
#include "SteeringForce.h"

class SteeringBehaviour : IBehaviour
{
public:
	SteeringBehaviour();
	~SteeringBehaviour();

	void Update(Agent* An_Agent, float DeltaTime) override;

private:

	SteeringForce* m_steeringForce;

};