#pragma once
#include "IBehaviour.h"
#include "SteeringForce.h"

class SteeringBehaviour : public IBehaviour
{
public:
	SteeringBehaviour();
	~SteeringBehaviour();

	void Update(Agent* An_Agent, float DeltaTime) override;

	SteeringForce* m_steeringForce;

private:


};