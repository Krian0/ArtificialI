#pragma once
#include "IBehaviour.h"
#include "SteeringForce.h"

class SteeringBehaviour : public IBehaviour
{
public:
	SteeringBehaviour();
	~SteeringBehaviour();

	void Update(Agent* An_Agent, float DeltaTime) override;
	void AddSteering(SteeringE Steering_Enum, SteeringForce* Steering_Force);
	void RemoveSteering(SteeringE Steering_Enum);

	map<SteeringE, SteeringForce*> m_steeringForce;

private:


};