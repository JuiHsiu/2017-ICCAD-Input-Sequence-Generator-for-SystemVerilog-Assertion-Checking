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
        Path_Judge(AssertionRule asrt);

        // Principle Functions
        void decide(AssertionRule& arst, vector <string>& input_lib,  vector< vector<Edge *> > edges);
        vector <string> out_weight_generator();
        vector <string> in_weight_generator();

    private:
        // Functions called by decide()
        int target_assertion(AssertionRule asrt);
        void path_maker( int seq , AssertionRule& asrt, vector<string>& input_lib,  vector< vector<Edge *> > edges, bool cBTWc, bool Lock_In);
        void initializer(vector<string>& input_lib , vector< vector<Edge *> > edges);
        // Functions called by cycle_path_maker

        void assertion_cleaner(AssertionRule asrt, vector< vector<Edge *> >& tmp_edge_path , vector<Edge *>  selected_edges, vector <string>& input_lib );
        void trigger_in_cycle(AssertionRule asrt, vector< vector<Edge *> >& tmp_edge_path , vector<Edge *>  selected_edges, vector <string>& input_lib);
        void cycle_path_maker( AssertionRule asrt, vector<Edge *>  selected_edges , vector <string> input_lib);
        void Max_delay( AssertionRule asrt);


        // Other variables
        vector<string> in_weight_seq;
        vector<string> out_weight_seq;
        bool trigger, cleaner, random;
        int NOT_triggered;
        string iPrev;       // path_maker()
        string zero;        // initializer()
        int  end,start,bit,out_bit,decideIndex, target_bit; // decide()
        char R_F, nR_F;     // decide()
        string desireVal_1, desireVal_2, copy_input_weight;
        int tmp_in_start, max;
};

#include "Path_Judge.cpp"
#endif // PATH_JUDGE_H
