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

class Agent
{

public:
	Agent() {}
	~Agent() {};

	virtual void Update(float DeltaTime) = 0;
	virtual void Draw(Renderer2D* renderer) = 0;

	//Sets m_force to the Vector2 parameter
	void AddForce(Vector2 force);
	//Makes the Agent's sprite flicker to a hit-sprite and back several times upon being hit
	void OnHit();
	//
	void OnFlee();

	//Set variable matching the function name
	void SetTargetList(vector<Agent*> Targets);
	void AddFriendToList(Agent* Friend);
	void AddSteering(SteeringE Steering_Enum, SteeringForce* Steering_Force);
	void RemoveSteering(SteeringE Steering_Enum);
	//~

	//Returns variable matching the function name
	vector<Agent*> GetTargets();
	vector<Agent*> GetFriends();

	Vector2	GetPos();
	Vector2 GetCurrentVelocity();

	float	GetRadius();
	bool	WasAttacked();
	bool	IsAgentPlayer();
	bool	IsColliding(Agent* The_Target);
	//~

	int m_sightRange;
	int m_attackRange;
	int m_velocityLimit;

protected:

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

	float	m_flickerTime;
	int		m_flickerCounter;
	bool	m_firstRound;
	bool	m_wasAttacked;
	bool	m_isPlayer;

private:

};