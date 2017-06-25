#include "graph.h"
#include "graph_path.h"

Graph_path::Graph_path(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph_path::addEdge(int u, int v)
{
    adj[u].push_back(v); // Add v to u’s list.
}

// Prints all paths from 's' to 'd'
// void Graph_path::printAllPaths(int s, int d, set<int> cycle_nodes)
void Graph_path::printAllPaths(int s, int d, vector< vector<int> > &path_vector2)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];

    // Create an array to store paths
    int *path = new int[V];
    int path_index = 0; // Initialize path[] as empty

    // Call the recursive helper function to print all paths
    printAllPathsUtil(s, d, visited, path, path_index, path_vector2);
    visited[s] == false;
    visited[d] == false;
}

// A recursive function to print all paths from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
void Graph_path::printAllPathsUtil(int u, int d, bool visited[],
                            int path[], int &path_index, vector< vector<int> > &path_vector2)
{
    // Mark the current node and store it in path[]
    visited[u] = true;
    path[path_index] = u;
    path_index++;

    // If current vertex is same as destination, then print
    // current path[]
    if (u == d)
    {
        for (int i = 0; i<path_index; i++){
//            cout << path[i] << " ";
            temp.push_back(path[i]);
        }
        path_vector2.push_back(temp);
        temp.clear();
//        cout << endl;
    }
    else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current vertex
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, d, visited, path, path_index, path_vector2);
    }

    // Remove current vertex from path[] and mark it as unvisited
    path_index--;
    if ((u == d) && (path_index == 0)) {
        visited[u] = false;        
    }
}

void Graph_path::initializeWithVector(Graph& fsm) 
{
    for(int i=0; i<fsm.nodes.size();i++){
        for(int j=0; j<fsm.nodes[i]->edge_out.size();j++){
            addEdge(fsm.nodes[i]->id, fsm.nodes[i]->edge_out[j]->node[1]->id );
        }
    } 
}

void Graph_path::path_gen(vector< vector<Edge *> > A, vector< vector<Edge *> > &storage, int col, vector<Edge *> path)
{
    if ( col == A.size()) {
        /*for(int i =0 ; i < 1; i++){
            cout<<path[i]<<" ";*/
        
        //cout<<endl;
        storage.push_back(path);
        path.pop_back();
        return;
        } else{
        for(int j =0 ; j< A[col].size();j++){
            path.push_back(A[col][j]);
            path_gen(A, storage, col+1, path);
            break;
        }
        path.pop_back();
    }
}

void Graph_path::finalPathGen(vector< vector<int> > path_list, Graph& fsm, vector< vector<Edge *> >& finalPath) 
{
    vector<Edge *> path_list_temp;
    vector< vector<Edge *> > pathOfAllPath;
	vector<Edge *> path;

    for (int i=0; i < path_list.size(); i++) {
        for (int j=0; j < path_list[i].size(); j++) {
            for (int k=0; k < fsm.nodes[path_list[i][j]]->edge_out.size(); k++) {
                if (fsm.nodes[path_list[i][j]]->edge_out[k]->node[1]->id == fsm.nodes[path_list[i][j+1]]->id) {
                    path_list_temp.push_back(fsm.nodes[path_list[i][j]]->edge_out[k]);
                }
            }
        if (path_list_temp.size() != 0) pathOfAllPath.push_back(path_list_temp);
        path_list_temp.clear();
        }
        path_gen(pathOfAllPath, finalPath, 0, path);
        pathOfAllPath.clear();
        path.clear(); 
    }
}
