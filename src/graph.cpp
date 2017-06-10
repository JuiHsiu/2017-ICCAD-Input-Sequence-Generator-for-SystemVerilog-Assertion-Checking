// **************************************************************************
// File       [ graph.cpp ]
// Author     [ Eddy Hsu ]
// Synopsis   [ This is a finite state machine. ]
// Date       [ 2017/06/09 created ]
// **************************************************************************
#include "graph.h"


Edge::Edge(Node *a, Node *b, string& iw, string& ow)
{
	node[0] = a; 
	node[1] = b;
	for(int i=0; i<iw.size(); i++) {
		input_weight.push_back(iw[i]);
	}		
	for(int i=0; i<iw.size(); i++) {
		output_weight.push_back(ow[i]);
	}	
}

bool Edge::operator < (const Edge& rhs) const{

	int id1a = node[0]->id;
	int id1b = node[1]->id;

	int id2a = rhs.node[0]->id;
	int id2b = rhs.node[1]->id;


	if ( id1a == id2a ) return id1b < id2b;
	if ( id1a == id2b ) return id1b < id2a;
	if ( id1b == id2a ) return id1a < id2b;
	if ( id1b == id2b ) return id1a < id2a;

	return output_weight < rhs.output_weight;
}
Node * Edge::getNeighbor(Node *n)
{
	if ( node[0] == n ) return node[1];
	if ( node[1] == n ) return node[0];

	return 0;	
}


Node::Node(const int& i)
{
	id = i;
	traveled = false;
	color = -1;
	d = DIS_INF;
	prev = 0;
}

void Node::addEdgeIn(Edge *e)
{
	edge_in.push_back(e);
}

void Node::addEdgeOut(Edge *e)
{
	edge_out.push_back(e);
}

bool edgeComp( const Edge* A, const Edge* B ){
	if ( (*A) < (*B) ) return true;
	return false;
}


void Node::sortEdgeIn()
{
    sort(edge_in.begin(), edge_in.end(), edgeComp);
}

bool edgeCompByOW( const Edge* A, const Edge* B ){
	if ( A->output_weight < B->output_weight ) return true;
	return false;
}

void Node::sortEdgeInByOutputWeight()
{
    sort(edge_in.begin(), edge_in.end(), edgeCompByOW);
}


Graph::Graph(const string& n)
{
	name = n;
}

Graph::~Graph()
{
	vector<Edge *>::iterator itE;
	for ( itE = edges.begin() ; itE != edges.end() ; itE++ )
	{
		delete (*itE);
		(*itE) = 0;
	}
	
	map<int, Node *>::iterator itN;
	for ( itN = nodesMap.begin() ; itN != nodesMap.end() ; itN++ )
	{
		delete (*itN).second;
		(*itN).second = 0;
	}

    /*vector<Node *>::iterator itN2;
	for ( itN2 = nodes.begin() ; itN2 != nodes.end() ; itN2++ )
	{
		(*itN2) = 0;
	}*/
}
		
void Graph::addEdge(const int& v1, const int& v2, string& iw, string& ow)
{
	Node *a, *b;
	map<int, Node *>::iterator it = nodesMap.find(v1);
	if ( it != nodesMap.end() )
		a = (*it).second;
	else
	{
		a = new Node(v1);
		nodesMap[v1] = a;
        nodes.push_back(a);
	}

	it = nodesMap.find(v2);
	if ( it != nodesMap.end() )
		b = (*it).second;
	else
	{
		b = new Node(v2);
		nodesMap[v2] = b;
        nodes.push_back(b);
	}

	Edge *e = new Edge(a, b, iw, ow);
	edges.push_back(e);

	a->edge_out.push_back(e);
	b->edge_in.push_back(e);

}
	
void Graph::sortEdgesInOfNode()
{
	map<int, Node *>::iterator it;
	for ( it = nodesMap.begin() ; it != nodesMap.end() ; it++ )
	{
		Node *node = (*it).second;
		node->sortEdgeIn();
	}

}

bool edgeCompByIW( const Edge* A, const Edge* B )
{
	if ( A->input_weight < B->input_weight ) return true;
	return false;
}

void Graph::sortEdgesByInputWeight()
{
    sort(edges.begin(), edges.end(), edgeCompByIW);
}


bool NodeCompByD( const Node* A, const Node* B )
{
	if ( A->edge_in.size() + A->edge_out.size() > B->edge_in.size() + B->edge_out.size() ) 
        return true;
    else if (A->edge_in.size() + A->edge_out.size() == B->edge_in.size() + B->edge_out.size()) {
        if (A->id < B->id) 
            return true;
        else 
            return false;
    }
    else
        return false;
}

void Graph::sortNodesByDegree()
{
    sort(nodes.begin(), nodes.end(), NodeCompByD);
}


bool NodeCompByID( const Node* A, const Node* B ){
	if ( A->id < B->id ) return true;
    else return false;
}

void Graph::sortNodesByID()
{
    sort(nodes.begin(), nodes.end(), NodeCompByID);
}

void Graph::init()
{
	map<int, Node *>::iterator itN;
	for ( itN = nodesMap.begin() ; itN != nodesMap.end() ; itN++ )
	{
		Node *node = (*itN).second;
		node->traveled = false;
		node->d = DIS_INF;
		node->prev = 0;
    	node->color = -1;
	}
	
}

void Graph::displayNodesAndEdges()
{
	cout << "# of state = " << nodes.size() << endl;
    for(int i=0; i<nodes.size();i++){
        cout << "s" << nodes[i]->id << ": " << endl;
        for(int j=0; j<nodes[i]->edge_out.size();j++){
        	for(int k=0; k<nodes[i]->edge_out[j]->input_weight.size(); k++)
        		cout << nodes[i]->edge_out[j]->input_weight[k];
        	cout << " s" << nodes[i]->edge_out[j]->getNeighbor(nodes[i])->id << " ";
        	for(int k=0; k<nodes[i]->edge_out[j]->output_weight.size(); k++)
        		cout << nodes[i]->edge_out[j]->output_weight[k];
        	cout << endl;
        }
        cout << endl;
    }
}

void Graph::countCycleNode()
{
	for(int i=0;i<edges.size();i++){
		if(edges[i]->node[0]==edges[i]->node[1])
			cout << "Cycle Node = s" << edges[i]->node[0]->id << endl;
	}
}

Node * Graph::getNodeById(const int& id)
{
	return nodesMap[id];
}

