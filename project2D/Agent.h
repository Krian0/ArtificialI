#pragma once
#include "BehaviourEnum.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "Vector2.h"
#include <vector>
#include <stack>
#include <map>
using std::map;
using std::stack;
using std::vector;
using aie::Texture;
using aie::Renderer2D;

class SteeringBehaviour;
class SteeringForce;
class StateMachine;
class IBehaviour;
class AStarGraph;
class BoxObject;

class Agent
{

public:
	Agent() {}
	~Agent() {};

	virtual void Update(float DeltaTime) = 0;
	virtual void Draw(Renderer2D* renderer) = 0;

	//Sets m_force to parameter. Takes a Vector2 as parameter
	void AddForce(Vector2 force);
	
	//Makes the Agent's sprite flicker to the hit-sprite and back several times upon being hit
	void OnHit();
	
	//Sets m_wasAttacked to false
	void OnFlee();
	
	//Handles collision through use of CollidePlus/CollideMinus. Takes two Vector2, a bool and a float as parameters
	void OnCollide(Vector2 Min, Vector2 Max, bool UsingAgent = false, float VelocityDegrade = 0.90f);
	
	//Handles collision through use of CollidePlus/CollideMinus. Takes a Vector2 as parameter
	void OnCollide(Vector2 OtherAgentPos);
	
	//Handles collision through for Objects specifically. Takes a BoxObject* as parameter
	void OnCollide(BoxObject* Object);

	//Sets m_pathfindingMode to given boolean value. Takes a bool as parameter
	void SetPathfindingMode(bool BooleanValue);
	
	//Set m_targets to given Agent vector. Takes an Agent* vector as parameter
	void SetTargetList(vector<Agent*> Targets);
	
	//Add given Agent to m_friends. Takes an Agent* as parameter
	void AddFriendToList(Agent* Friend);
	
	//Sets m_objects to given BoxObject vector. Takes a BoxObject* vector as parameter
	void AddObjects(vector<BoxObject*> Objects);
	
	//Set State at given Steering Enum in SteeringForce map to given SteeringForce. Takes a SteeringE (Enum) and SteeringForce* as parameters
	void AddSteering(SteeringE Steering_Enum, SteeringForce* Steering_Force);
	
	//Set State at given Steering Enum in SteeringForce map to NULL. Takes a SteeringE (Enum) as parameter
	void RemoveSteering(SteeringE Steering_Enum);

	//Returns Agent* vector m_targets
	vector<Agent*> GetTargets();
	
	//Returns Agent* vector m_friends
	vector<Agent*> GetFriends();
	
	//Returns BoxObject* vector m_objects
	vector<BoxObject*> GetObjects();
	
	//Returns Vector2 m_position
	Vector2	GetPos();
	
	//Returns Vector2 m_velocity
	Vector2 GetCurrentVelocity();

	//Returns float m_radius
	float	GetRadius();
	
	//Returns bool m_wasAttacked. Used in AttackState
	bool	WasAttacked();
	
	//Returns bool m_isPlayer. Used in controlling States for the player (mainly in AttackState)
	bool	IsAgentPlayer();
	
	//Returns true if given Vector2 (with a radius of Agent's radius) intersects with Agent, otherwise returns false. Takes a Vector2 as parameter
	bool	IsCollidingWithNode(Vector2 Point);
	
	//Returns true if parameter Agent is colliding with the Agent, otherwise returns false. Takes an Agent* as parameter
	bool	IsColliding(Agent* The_Target);
	
	//Returns bool m_pathfindingMode
	bool	PathfindingModeIsOn();

	//Return a Vector2 stack through AStar with the closest Node to Agent (start) and a random target Node (end)
	stack<Vector2> GetPathfindingVectors();


	Vector2 m_currentlySeeking;

	int m_sightRange;
	int m_attackRange;
	int m_velocityLimit;

protected:

	//Move Agent so that they no longer collide, reverse velocity. Takes four float and a bool as parameters
	void CollidePlus(float Boundary, float DegradeValue, float &Pos, float &Vel, bool UsingAgent);
	
	//Move Agent so that they no longer collide, reverse velocity. Takes four float and a bool as parameters
	void CollideMinus(float Boundary, float DegradeValue, float &Pos, float &Vel, bool UsingAgent);
	

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

	Vector2 m_windowSize;
	vector<Agent*> m_targets;
	vector<Agent*> m_friends;
	vector<BoxObject*> m_objects;

	AStarGraph*	m_pathfinding;

	float	m_flickerTime;
	int		m_flickerCounter;
	bool	m_firstRound;
	bool	m_wasAttacked;
	bool	m_isPlayer;
	bool	m_pathfindingMode;
};