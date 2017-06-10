// **************************************************************************
// File       [ main.cpp ]
// Author     [ Eddy Hsu ]
// Synopsis   [ This is a fianl project of 2017 Algorithms ]
// Date       [ 2017/06/09 created ]
// **************************************************************************

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cstring>
#include <vector>
#include "graph.h"
#include "assertion_rule.h"
#include "assertion_parser.h"
#include "fsm_parser.h"

using namespace std;


//void help_message() {
//	// 正式的輸入格式“time your_program_name –i fsm.v –o input_sequence”
//	// cout << "usage: time NTULoners –i fsm.v –o input_sequence" << endl;
//    cout << "usage: NTULoners BF <input_file>" << endl;
//    cout << "options:" << endl;
//    cout << "   BF  - Brute Force" << endl;
//}

int main(int argc, char **argv) {
//	if(argc != 3) {
//       help_message();
//       return 0;
//    }
    
    //////////// read the input file /////////////	
    AssertionRule assertion_rule;
    vector<string> req, delay, ack;
	collect_assertion(argv[1], req, delay, ack);
	for(int i=0; i<req.size(); i++) {
		assertion_rule.addAsertionRules(i+1, req[i], delay[i], ack[i]);
	}	
	assertion_rule.displayAssertionRules();
	
	Graph fsm("Final project is very hard!");
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
    fsm.displayNodesAndEdges();
    fsm.countCycleNode();
	
//	fstream fout;
//	fout.open("input_sequence",ios::out);

	
    //////////// find the input sequences for assertion failed /////////////	
//	Graph* pa3_graph = new Graph("fsm_graph");
	
//	if(strcmp(argv[1], "-BF") == 0) {
////    	BruteForce();// Brute Force Algorithm 
//    }
//    else {
//        help_message();
//        return 0;
//    }
	

    
	//////////// write the output file ///////////
//	fin.close();
//	fout.close();
	
    return 0;
}
