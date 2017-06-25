#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "graph.h"
#include "graph_path.h"
#include <iostream>
#include <vector>
#include <string>
#include "graph.h"
#include "assertion_rule.h"
#include "assertion_parser.h"
#include "fsm_parser.h"
#include "Path_Judge.h"


vector<string> input_lib;


using namespace std;

int main(int argc, char **argv) {
    //////////// build the AssertionRule from input file /////////////
    AssertionRule assertion_rule;
    vector<string> req, delay, ack;
    collect_assertion(argv[1], req, delay, ack);
    for(int i=0; i<req.size(); i++) {
        assertion_rule.addAsertionRules(i+1, req[i], delay[i], ack[i]);
    }
//    assertion_rule.displayAssertionRules();

	//////////// build the Finite State Machine (FSM) from input file /////////////
    Graph fsm;
    vector < vector <int> > adj_list;
    vector < vector <string> > input_list;
    vector < vector <string> > output_list;
    fsm_parser(argv[1], adj_list, input_list, output_list);
    for(int i=0; i<output_list.size();i++){
        for(int j=0; j<output_list[i].size();j++){
            fsm.addEdge(i, adj_list[i][j], input_list[i][j], output_list[i][j]);
        }
    }
    fsm.sortNodesByID();
//    fsm.displayNodesAndEdges();
    fsm.countCycleNode();
	
	//////////// generate input sequence /////////////
	Graph_path g(adj_list.size());
	Path_Judge p_(assertion_rule);
	int last_failed_rule = -1, curr_failed_rule = 0, terminate = 0;
	int node_count = 0, step = 3;
		
	while(terminate != 5) {
		//////////// condition of termination /////////////
		if(last_failed_rule == curr_failed_rule)
			terminate++;
//		cout << "last_failed_rule = " << last_failed_rule << endl;
//		cout << "curr_failed_rule = " << curr_failed_rule << endl;
		last_failed_rule = curr_failed_rule;
		
		//////////// set source Node and destinate Node /////////////
		int source_node = node_count % fsm.cycle_node.size();
		int destinate_node = (node_count + step) % fsm.cycle_node.size();
		source_node = fsm.cycle_node[source_node];
		destinate_node =  fsm.cycle_node[destinate_node];
		if(node_count == 0)
			source_node = 0;
//		int source_node = 0, destinate_node = 10;
		node_count = node_count + step;
		
		//////////// print the path by DFS /////////////
	    vector< vector<int> > path_list;
	    g.initializeWithVector(fsm);
	
	    cout << "Following are all different paths from " << source_node << " to " << destinate_node << endl;
	    g.printAllPaths(source_node, destinate_node, path_list);
	
	    //////////// save all the path to pathOfAllPath/////////////	    
	    sort( path_list.begin(), path_list.end() );
	    path_list.erase( unique( path_list.begin(), path_list.end() ), path_list.end() );
	    
	    vector<Edge *> path_list_temp; 
	    vector< vector<Edge *> > pathOfAllPath;
	    vector< vector<Edge *> > finalPath;
	    vector<Edge *> path;
	    
	    for (int i=0; i < path_list.size(); i++) {
	        for (int j=0; j < path_list[i].size()-1; j++) {
	            for (int k=0; k < fsm.nodes[path_list[i][j]]->edge_out.size(); k++) {
	                if (fsm.nodes[path_list[i][j]]->edge_out[k]->node[1]->id == fsm.nodes[path_list[i][j+1]]->id) {
	                    path_list_temp.push_back(fsm.nodes[path_list[i][j]]->edge_out[k]);
	                }
	            }
	        if (path_list_temp.size() != 0) pathOfAllPath.push_back(path_list_temp);
	        path_list_temp.clear();
	        }
	        g.path_gen(pathOfAllPath, finalPath, 0, path);
	        pathOfAllPath.clear();
	        path.clear(); 
	    }   
	    
	        for (int i=0; i < finalPath.size(); i++){
	            cout << finalPath[i][0]->node[0]->id;
	            for (int j=0; j < finalPath[i].size(); j++) {
	                cout << " -> " << finalPath[i][j]->node[1]->id;
	            }
	            cout << endl;
	        }
	
		//////////// decide a path and store into input_lib/////////////
		if (finalPath.size() == 0) {
			destinate_node += 1;
			destinate_node = destinate_node % fsm.cycle_node.size();
			continue;		
		}
	    p_.decide(assertion_rule, input_lib, finalPath);
	    vector <string> input_seq =  p_.in_weight_generator();
	    vector <string> output_seq = p_.out_weight_generator();
	
	    input_seq =  p_.in_weight_generator();
	    output_seq = p_.out_weight_generator();
		
//	    cout<<"generated input sequence = ";
//	    for (int i =0 ;i < input_seq.size() ; i++){
//	        cout<<input_seq[i]<<"    ";
//	    }
//	    cout<<endl;
//	    cout<<"generated output sequence = ";
//	    for (int i =0 ;i < output_seq.size() ; i++){
//	        cout<<output_seq[i]<<"    ";
//	    }
//	    cout<<endl;
			
		//////////// compute current failed assertion rule/////////////
		curr_failed_rule = 0;
		for(int i=0; i<assertion_rule.rules.size(); i++) {
			if(assertion_rule.rules[i]->flag)
				assertion_rule.rules[i]->ruleChecker(input_seq, output_seq);
			if(!assertion_rule.rules[i]->flag)
				curr_failed_rule++;
		}
			
	}
	
	//////////// print current failed assertion rule/////////////
	cout << "--------------------------------" << endl;
	cout << "There are totally " << curr_failed_rule << " assertion rules failed!" << endl;
	for(int i=0; i<assertion_rule.rules.size(); i++) {
		if(!assertion_rule.rules[i]->flag)
			cout << "assertion rule " << assertion_rule.rules[i]->id << " failed" << endl;
	}
	cout << endl;
	cout << "input sequence size = " << input_lib.size();
    
    //////////// creat input_sequence file /////////////
    fstream fout;
    string output_filename = "fsm";
	output_filename.push_back(argv[1][3]);
	output_filename = output_filename + "_input_sequence.txt";
	fout.open(output_filename.c_str() ,ios::out);
	for(int i=0; i<input_lib.size(); i++)
		fout << input_lib[i] << endl;
	fout.close();
    
    return 0;
}
