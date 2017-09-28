#pragma once
#include "IBehaviour.h"
#include "BehaviourEnum.h"
#include <map>
using std::map;

class SteeringForce;

class SteeringBehaviour : public IBehaviour
{
public:
	SteeringBehaviour();
	~SteeringBehaviour();

	//Calculates a Vector2 Force and adds it to given Agent using AddForce. Takes an Agent* and a float as parameters
	void Update(Agent* An_Agent, float DeltaTime) override;
	
	//Sets SteeringForce at the given Steering Enum to the given SteeringForce*. Takes a SteeringE (Enum) and a SteeringForce* as parameters
	void AddSteering(SteeringE Steering_Enum, SteeringForce* Steering_Force);
	
	//Sets SteeringForce at the given Steering Enum to NULL. Takes a SteeringE (Enum) as parameter
	void RemoveSteering(SteeringE Steering_Enum);


	map<SteeringE, SteeringForce*> m_steeringForce;
};