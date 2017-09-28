#pragma once
#include "Vector2.h"
#include <vector>
#include <stack>
#include <list>
using std::vector;
using std::stack;
using std::list;

struct Node;
struct Edge;

class BoxObject;
class Agent;

class AStarGraph
{
public:
	AStarGraph();
	~AStarGraph();

	//Create Nodes, set position/edges, remove any Nodes colliding with Objects* vector
	//Takes two unsigned ints, a BoxObject* vector and a Vector2 as parameters
	void SetGraphNodes(unsigned int NodesInRow, unsigned int NodesInColumn, vector<BoxObject*> Objects, Vector2 WindowSize);
	
	//Finds and returns the Node* on the Graph closest to the given Agent. Takes an Agent* as parameter
	Node* FindClosestNode(Agent* An_Agent);

	//Return a Vector2 stack of the shortest path between the given Nodes. Takes two Node* as parameters
	stack<Vector2> AStarSearch(Node* Start_Node, Node* End_Node);


	vector<Node*> m_nodes;

private:
	//Push back a new Node to m_nodes, set Node ID to Index. Takes an unsigned int as parameter
	void AddNode(unsigned int Index);
	
	//Removes a Node by the given Index. Takes an unsigned int as parameter
	void RemoveNode(unsigned int Index);
	
	//Removes a Node by a given Node*. Takes a Node* as parameter
	void RemoveNode(Node* The_Node);
	
	//Push back a new Edge between each Node*, to each Node*. Takes two Node* as parameters
	void AddEdge(Node* Node1, Node* Node2);

	//Returns true if an Edge already exists starting from NodeA* ending at NodeB*, otherwise returns false. Takes two Node* as parameters
	bool DoesEdgeExist(Node* NodeA, Node* NodeB);
	
	//Returns true if the given Node* is on the given Node* List, otherwise returns false. Takes a Node* and a Node* list as parameters
	bool IsNodeOnList(Node* The_Node, list<Node*> Node_List);
};