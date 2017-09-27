#include "AStarGraph.h"
#include "BoxObject.h"
#include "Agent.h"

AStarGraph::AStarGraph()
{
	m_windowExtents = Vector2(1280, 720);
}

AStarGraph::~AStarGraph()
{
	for (auto N : m_nodes)
		N->m_edges.clear();

	m_nodes.clear();
}


void AStarGraph::SetGraphNodes(unsigned int NodesInRow, unsigned int NodesInColumn, vector<BoxObject*> Objects)
{
	for (unsigned int i = 0; i < (NodesInRow * NodesInColumn); i++)
		AddNode(i);


	int NodeNum = 0;
	float SpaceX = m_windowExtents.x / NodesInColumn;
	float SpaceY = m_windowExtents.y / NodesInRow;
	Vector2 LastVec(SpaceX / 2, SpaceY / 2);


	for (unsigned int r = 0; r < NodesInRow; r++)
	{
		for (unsigned int c = 0; c < NodesInColumn; c++)
		{
			//Set up Node position
			if (NodeNum > 0)
			{
				LastVec.x += SpaceX;
				if (LastVec.x > m_windowExtents.x)
					LastVec = Vector2(SpaceX / 2, LastVec.y += SpaceY);
			}

			m_nodes[NodeNum]->m_position = LastVec;


			//Set up Node Edges
			if (r != (NodesInRow - 1))
				AddEdge(m_nodes[NodeNum], m_nodes[(NodeNum + NodesInColumn)]);

			if (c != (NodesInColumn - 1))
				AddEdge(m_nodes[NodeNum], m_nodes[(NodeNum + 1)]);


			NodeNum++;
		}
	}

	//Remove any Nodes colliding with any Objects
	for (auto OB : Objects) 
		for (unsigned int i = 0; i < m_nodes.size(); i++) 
			if (OB->IsColliding(m_nodes[i]->m_position))
				RemoveNode(i);
}

Node* AStarGraph::FindClosestNode(Agent* An_Agent)
{
	Node* ClosestNode;
	float LastDistance = 99999;

	for (auto N : m_nodes)
	{
		float CurrentDistance = (An_Agent->GetPos() - N->m_position).magnitude();

		if (CurrentDistance < LastDistance)
		{
			ClosestNode = N;
			LastDistance = CurrentDistance;
		}
	}

	return ClosestNode;
}

stack<Vector2> AStarGraph::BreadthFirstSearch(Node* Start_Node, Node* End_Node)
{
	for (auto Nodes : m_nodes)
	{
		Nodes->m_parent = nullptr;
		Nodes->m_gScore = 0;
	}

	list<Node*> OpenList;
	list<Node*> ClosedList;
	Node*		CurrentNode;

	OpenList.push_back(Start_Node);

	while (OpenList.empty() != true)
	{
		OpenList.sort();

		CurrentNode = OpenList.front();
		if (CurrentNode == End_Node)
			break;

		OpenList.pop_front();
		ClosedList.push_back(CurrentNode);

		
		for (auto Edges : CurrentNode->m_edges)
		{
			Node* ENode = Edges->m_end;

			if (IsNodeOnList(ENode, ClosedList) == false)
			{
				ENode->m_gScore = CurrentNode->m_gScore + Edges->m_cost;
				ENode->m_hScore = ENode->m_position.dot(End_Node->m_position);
				ENode->m_fScore = ENode->m_gScore + ENode->m_hScore;

				ENode->m_parent = CurrentNode;
				OpenList.push_back(ENode);
			}
		}
	}

	stack<Vector2> Path;
	
	CurrentNode = End_Node;
	while (CurrentNode != nullptr)
	{
		Path.push(CurrentNode->m_position);
		CurrentNode = CurrentNode->m_parent;
	}

	return Path;
}


void AStarGraph::AddNode(unsigned int Index)
{
	m_nodes.push_back(new Node);
	m_nodes.back()->m_nodeID = Index;
}

void AStarGraph::RemoveNode(unsigned int Index)
{
	RemoveNode(m_nodes[Index]);
}

void AStarGraph::RemoveNode(Node* The_Node)
{
	//Goes through all Edges for the Node
	for (auto E : The_Node->m_edges)
	{
		//Sets the connected Node (CN) to the target of the current (The_Node) Edge
		Node* CN = E->m_end;

		//Goes through all (CN) Edges and deletes any (CN) Edges whose target is the The_Node
		for (auto CNE = CN->m_edges.begin(); CNE != CN->m_edges.end(); )
		{
			if ((*CNE)->m_end == The_Node)
				CNE = CN->m_edges.erase(CNE);
			else
				++CNE;
		}
	}


	m_nodes.erase(m_nodes.begin() + The_Node->m_nodeID);
}


void AStarGraph::AddEdge(Node* Node1, Node* Node2)
{
	if (DoesEdgeExist(Node1, Node2) == false)
		Node1->m_edges.push_back(new Edge(Node1, Node2));

	if (DoesEdgeExist(Node2, Node1) == false)
		Node2->m_edges.push_back(new Edge(Node2, Node1));
}

bool AStarGraph::DoesEdgeExist(Node* NodeA, Node* NodeB)
{
	for (auto Edges : NodeA->m_edges)
		if (Edges->m_end == NodeB)
				return true;

	return false;
}

bool AStarGraph::IsNodeOnList(Node* The_Node, list<Node*> Node_List)
{
	for (auto NL : Node_List)
		if (The_Node == NL)
			return true;

	return false;
}