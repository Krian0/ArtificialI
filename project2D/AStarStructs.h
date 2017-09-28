#pragma once
#include "Vector2.h"
#include <vector>
using std::vector;

struct Edge;

struct Node
{
	Vector2 m_position;
	Node* m_parent;

	float m_gScore;
	float m_hScore;
	float m_fScore;

	int m_nodeID;

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