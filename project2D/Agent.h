#pragma once
#include "Vector2.h"
#include "Texture.h"
#include "Renderer2D.h"
#include "IBehaviour.h"
#include "StateMachine.h"
using aie::Texture;
using aie::Renderer2D;

class SteeringBehaviour;
class SteeringForce;
class BoxObject;

class Agent
{

public:
	Agent() {}
	~Agent() {};

	virtual void Update(float DeltaTime) = 0;
	virtual void Draw(Renderer2D* renderer) = 0;

	//Sets m_force to parameter. Takes Vector2 parameter
	void AddForce(Vector2 force);
	//Makes the Agent's sprite flicker to the hit-sprite and back several times upon being hit
	void OnHit();
	//Sets m_wasAttacked to false
	void OnFlee();
	//Handles collision through use of CollidePlus/CollideMinus. Takes a float and two Vector2 parameters
	void OnCollide(Vector2 Min, Vector2 Max, bool UsingAgent = false, float VelocityDegrade = 0.90f);
	//Handles collision through use of CollidePlus/CollideMinus. Takes a float and a Vector2 parameter
	void OnCollide(Vector2 OtherAgentPos);
	//
	void OnCollide(BoxObject* Object, float VelocityDegrade = 0.90f);


	//
	void SetPathfindingMode(bool BooleanValue);
	//Set m_targets to parameter. Takes a vector of Agent pointers parameter
	void SetTargetList(vector<Agent*> Targets);
	//Add parameter to m_friends. Takes an Agent pointer parameter
	void AddFriendToList(Agent* Friend);
	//
	void AddObjects(vector<BoxObject*> Objects);
	//Used by states to set corresponding State in SteeringForce map to second parameter. Takes a SteeringE (enum) and SteeringForce pointer parameter
	void AddSteering(SteeringE Steering_Enum, SteeringForce* Steering_Force);
	//Used by states to set corresponding State in SteeringForce map to NULL. Takes a SteeringE (enum) parameter
	void RemoveSteering(SteeringE Steering_Enum);


	//Returns m_targets
	vector<Agent*> GetTargets();
	//Returns m_friends
	vector<Agent*> GetFriends();
	//
	vector<BoxObject*> GetObjects();
	//Returns m_position
	Vector2	GetPos();
	//Returns m_velocity
	Vector2 GetCurrentVelocity();

	//Returns m_radius
	float	GetRadius();
	//Returns m_wasAttacked. Used in AttackState
	bool	WasAttacked();
	//Returns m_isPlayer. Used in controlling States for the player (mainly in AttackState)
	bool	IsAgentPlayer();
	//Returns true if Agent is colliding with the parameter Agent. Takes an Agent pointer parameter
	bool	IsColliding(Agent* The_Target);
	//
	bool	PathfindingModeIsOn();


	int m_sightRange;
	int m_attackRange;
	int m_velocityLimit;

protected:

	//Pos = Boundary + Radius, Vel = -(Vel = DegradeValue). Takes five float parameters.
	void CollidePlus(float Boundary, float DegradeValue, float &Pos, float &Vel, bool UsingAgent);
	//Pos = Boundary - Radius, Vel = -(Vel = DegradeValue). Takes five float parameters.
	void CollideMinus(float Boundary, float DegradeValue, float &Pos, float &Vel, bool UsingAgent);
	
	Vector2 m_windowSize = Vector2(1280, 720); //Change this to window size if needed, window collision relies on it

	//Body
	Texture* m_sprite;
	Texture* m_hitSprite;

	Vector2 m_position;
	Vector2 m_force;
	Vector2 m_velocity;

	float	m_radius;

	//Brain
	map<BehaviourE, IBehaviour*> m_behaviours;
	StateMachine* m_stateMachine;

	vector<Agent*> m_targets;
	vector<Agent*> m_friends;
	vector<BoxObject*> m_objects;

	float	m_flickerTime;
	int		m_flickerCounter;
	bool	m_firstRound;
	bool	m_wasAttacked;
	bool	m_isPlayer;
	bool	m_pathfindingMode;

private:

};