#ifndef GRAPH_PATH_H
#define GRAPH_PATH_H

// C++ program to print all paths from a source to destination.
#include <iostream>
#include <list>
using namespace std;

// A directed graph using adjacency list representation
class Graph_path
{
private:
    int V; // No. of vertices in graph
    list<int> *adj; // Pointer to an array containing adjacency lists

    // A recursive function used by printAllPaths()
    void printAllPathsUtil(int , int , bool [], int [], int &);

public:
    Graph_path(int V); // Constructor
    void addEdge(int u, int v);
    void printAllPaths(int s, int d);
};
#include "graph_path.cpp"
#endif
