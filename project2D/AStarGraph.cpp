#include "AStarGraph.h"

AStarGraph::AStarGraph()
{
}

AStarGraph::~AStarGraph()
{
	for (unsigned int i = 0; i < m_nodes.size(); i++)
		m_nodes[i]->m_edges.clear();

	m_nodes.clear();
}


void AStarGraph::SetGraphNodes(unsigned int NodesInRow, unsigned int NodesInColumn)
{
	Vector2 WindowExtents(1280, 720);

	float SpaceX = WindowExtents.x / NodesInColumn;
	float SpaceY = WindowExtents.y / NodesInRow;

	for (unsigned int i = 0; i < (NodesInRow * NodesInColumn); i++)
		AddNode();

	int NodeNum = 0;
	Vector2 LastVec(SpaceX / 2, SpaceY / 2);


	for (unsigned int r = 0; r < NodesInRow; r++)
	{
		for (unsigned int c = 0; c < NodesInColumn; c++)
		{
			//Set up Node position
			if (NodeNum > 0)
			{
				LastVec.x += SpaceX;
				if (LastVec.x > WindowExtents.x)
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
}

void AStarGraph::AddNode()
{
	m_nodes.push_back(new Node);
}

void AStarGraph::RemoveNode(unsigned int Index)
{
	//Goes through all Edges for Node at Index (IndexNode)
	for (unsigned int i = 0; i < m_nodes[Index]->m_edges.size(); i++)
	{
		//Sets ConnectedNode to the target of the current (IndexNode) Edge
		Node* ConnectedNode = m_nodes[Index]->m_edges[i]->m_end;


		//Goes through all (ConnectedNode) Edges in reverse and deletes any (ConnectedNode) Edges whose target is the IndexNode
		for (int e = ConnectedNode->m_edges.size(); e >= 0; e--)
			if (ConnectedNode->m_edges[e]->m_end == m_nodes[Index])
				ConnectedNode->m_edges.erase(ConnectedNode->m_edges.begin() + e);
	}


	//Remove the Node at the position of the given Index
	m_nodes.erase(m_nodes.begin() + Index);
}


void AStarGraph::AddEdge(Node* Node1, Node* Node2)
{ 
	if (DoesEdgeExist(Node1, Node2) == false)
		Node1->m_edges.push_back(new Edge(Node1, Node2));

	if (DoesEdgeExist(Node2, Node1) == false)
		Node2->m_edges.push_back(new Edge(Node2, Node1));
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
				ENode->m_hScore = GetHScore(ENode, End_Node);
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


bool AStarGraph::DoesEdgeExist(Node* NodeA, Node* NodeB)
{
	for (unsigned int i = 0; i < NodeA->m_edges.size(); i++)
		if (NodeA->m_edges[i]->m_end == NodeB)
				return true;

	return false;
}

bool AStarGraph::IsNodeOnList(Node* The_Node, list<Node*> The_List)
{
	for (auto ListNode : The_List)
	{
		if (The_Node == ListNode)
			return true;
	}

	return false;
}

float AStarGraph::GetHScore(Node* NodeA, Node* NodeB)
{
	return NodeA->m_position.dot(NodeB->m_position);
}