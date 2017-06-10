/*
Filename: assertion_parser.h
Author:  Brady Huang
Description: this function extract the assertion rules in 3 string vectors: con, con_delay, res
Revision:   V.2017.5.17  
*/
#ifndef ASSERTION_PARSER_H
#define ASSERTION_PARSER_H
#include <vector>

void collect_assertion(char *filename, vector<string>& con, vector<string>& con_delay, vector<string>& res);


#include "assertion_parser.cpp"
#endif
