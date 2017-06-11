// **************************************************************************
// File       [ main.cpp ]
// Author     [ Michael Lee ]
// Synopsis   [ This file decides a path between two cycles and return that path ]
// Date       [ 2017/06/10 created ]
// **************************************************************************


#ifndef PATH_JUDGE_H
#define PATH_JUDGE_H
#include <iostream>
#include <vector>
#include <string>
#include "graph.h"
#include <vector>
#include <string>
#include "graph.h"
#include "assertion_rule.h"


class Path_Judge
{
    public:
        Path_Judge();
        vector<string> in_weight_seq;
        vector<string> out_weight_seq;
        // Functions
        int target_assertion(AssertionRule asrt);
        vector <string> decide(AssertionRule& arst, vector <string> input_lib,  vector< vector<Edge *> >& edges);
        vector <string> out_weight_generator();
        void path_maker( int seq , vector<string>& input_lib,  vector< vector<Edge *> >& edges);
        void initializer(vector<string>& input_lib , vector< vector<Edge *> > edges);

    private:

        bool trigger;
        int NOT_triggered;
        string iPrev;       // path_maker()
        string zero;        // initializer()
        int  end,start,bit; // decide()
        char R_F, nR_F;           // decide()
};

#include "Path_Judge.cpp"
#endif // PATH_JUDGE_H
