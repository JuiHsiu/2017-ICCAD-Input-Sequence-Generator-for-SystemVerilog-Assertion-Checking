// **************************************************************************
// File       [ graph.h ]
// Author     [ Eddy Hsu ]
// Synopsis   [ This is a finite state machine. ]
// Date       [ 2017/06/09 created ]
// **************************************************************************
#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>

#define DIS_INF 2147483647

using namespace std;

class Node;

class Edge{

	public:
		Edge(Node *a, Node *b, string& iw, string& ow);
		Node* node[2]; // node[0] ---> node[1]
		string input_weight;
		string output_weight;

		bool operator < (const Edge& rhs) const;
};

class Node{

	public:
		Node(const int& i);
		void addEdgeIn(Edge *e);
		void addEdgeOut(Edge *e);
		void sortEdgeIn();
		void sortEdgeInByOutputWeight();

		int id;
		int color;
		bool traveled;
		vector<Edge *> edge_in;
		vector<Edge *> edge_out;

		int d;
		Node *prev;
		int heap_idx;
};

class Graph{

	public:
		Graph();
		~Graph();
		
		void initializeWithVector(vector < vector <int> >& adj_list, vector < vector <string> >& input_list, vector < vector <string> >& output_list);
		void addEdge(const int& v1, const int& v2, string& iw, string& ow);
		void sortEdgesInOfNode();
		void sortEdgesByInputWeight();
		void sortNodesByDegree();
		void sortNodesByID();
		void init();
		void displayNodesAndEdges();
		void countCycleNode();
		Node * getNodeById(const int& id);

		map<int, Node *> nodesMap;
		vector<Node *> nodes;
		vector<Edge *> edges;
		vector<int> cycle_node;		
};
#include "graph.cpp"
#endif
