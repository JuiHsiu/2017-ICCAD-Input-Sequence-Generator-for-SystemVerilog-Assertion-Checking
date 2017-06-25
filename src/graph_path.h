#ifndef GRAPH_PATH_H
#define GRAPH_PATH_H

// C++ program to print all paths from a source to destination.
#include <iostream>
#include <list>
#include <set>
#include <vector>
#include "graph.h"
using namespace std;

// A directed graph using adjacency list representation
class Graph_path
{
private:
    int V; // No. of vertices in graph
    list<int> *adj; // Pointer to an array containing adjacency lists
    vector<int> temp;


    // A recursive function used by printAllPaths()
    void printAllPathsUtil(int , int , bool [], int [], int &, vector< vector<int> > &);

public:
    vector<Edge *> path;    
    Graph_path(int V); // Constructor
    void addEdge(int u, int v);
    void printAllPaths(int s, int d, vector< vector<int> > &);
    void initializeWithVector(Graph& fsm);
    void path_gen(vector< vector<Edge *> > A, vector< vector<Edge *> >& storage, int col, vector<Edge *> path);
    void finalPathGen(vector< vector<int> > path_list, Graph& fsm, vector< vector<Edge *> >& finalPath);
};
#include "graph_path.cpp"
#endif

