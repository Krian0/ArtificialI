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

class AStarGraph
{
public:
	AStarGraph();
	~AStarGraph();

	void SetGraphNodes(unsigned int NodesInRow, unsigned int NodesInColumn);

	//Push back a new Node to m_nodes
	void AddNode();
	//Removes the Node in m_nodes at the given (unsigned int) Index. Takes an unsigned int parameter
	void RemoveNode(unsigned int Index);

	//Push back a new Edge between each Node, to each Node. Takes two Node* parameters
	void AddEdge(Node* Node1, Node* Node2);

	stack<Vector2> BreadthFirstSearch(Node* Start_Node, Node* End_Node);


	vector<Node*> m_nodes;

private:

	//Returns true if an Edge already exists starting from NodeA ending at NodeB, otherwise returns false. Takes two Node* parameters
	bool DoesEdgeExist(Node* NodeA, Node* NodeB);
	//Returns true if the given Node is on the given List. Used in BFS. Takes a Node* parameter and a Node* list parameter
	bool IsNodeOnList(Node* The_Node, list<Node*> The_List);
	//
	float GetHScore(Node* NodeA, Node* NodeB);

};


struct Node
{
	Vector2 m_position;
	Node* m_parent;

	float m_gScore;
	float m_hScore;
	float m_fScore;

	vector<Edge*> m_edges;

	bool operator < (const Node& RHS) const
	{
		return (m_fScore < RHS.m_fScore);
	}
};

struct Edge
{
	Node* m_start;
	Node* m_end;
	float m_cost;

	Edge(Node* Start = nullptr, Node* End = nullptr, float Cost = 1) : m_start(Start), m_end(End), m_cost(Cost) {}
};