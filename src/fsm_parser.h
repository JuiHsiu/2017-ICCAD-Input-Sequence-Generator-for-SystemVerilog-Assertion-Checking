// **************************************************************************
// File       [ fsm_parser.h ]
// Author     [ Michael ]
// Synopsis   [ Read the nodes of the finite machine, and the input/output corresponding to a node]
// Date       [ 2017/05/15 created ]
// **************************************************************************
#ifndef FSM_PARSER_H
#define FSM_PARSER_H

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <queue>
#include <vector>

using namespace std;

void fsm_parser(char *filename, vector<vector<int> >& adj_list, vector<vector<string> >& input_list, vector<vector<string> >& output_list);


#include "fsm_parser.cpp"
#endif
