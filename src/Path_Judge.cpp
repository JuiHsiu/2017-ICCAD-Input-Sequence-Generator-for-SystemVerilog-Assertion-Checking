// **************************************************************************
// File       [ main.cpp ]
// Author     [ Michael Lee ]
// Synopsis   [ This file decides a path between two cycles and return that path ]
// Date       [ 2017/06/10 created ]
// **************************************************************************

#include "Path_Judge.h"


Path_Judge::Path_Judge()
{
    trigger = 0;
    NOT_triggered = 0;
}

int Path_Judge::target_assertion(AssertionRule asrt){
    for(int i = ++NOT_triggered; i < asrt.rules.size() ; i++){
        if ( asrt.rules[i] -> flag == true  ){
            return i;
        }
        else if(i == asrt.rules.size()-1){
            cout<<"all assertions already failed!"<<endl;
            trigger = 1;
            return -1;
        }
    }
}

void Path_Judge::path_maker( int seq ,vector<string>& input_lib,  vector< vector<Edge *> >& edges){
        int edge = 0;

            cout<<"unprocessed input was"<<endl;
            for (int i =0 ;i < edges[seq].size() ; i++){
                cout<<edges[seq][i]->input_weight<<"    ";
            }
            cout<<endl;

            while( edge < edges[seq].size()){ // before the end of edge sequence

                for( int bit = 0; bit < edges[seq][edge]->input_weight.size(); bit++){ // check each bit on a edge

                    if ( edges[seq][edge]->input_weight[bit] == 'x'){
                        iPrev = input_lib[input_lib.size()-1];
                        edges[seq][edge]->input_weight[bit] = (iPrev[bit] =='1'?'0':'1');
                    }

                }

                // push this input or output weight

                input_lib.push_back(edges[seq][edge]->input_weight);
                in_weight_seq.push_back(edges[seq][edge]->input_weight);
                out_weight_seq.push_back(edges[seq][edge]->output_weight);
                edge++;
            }
            trigger = 1;
}

void Path_Judge::initializer(vector<string>& input_lib , vector< vector<Edge *> > edges){
    cout<<"initializing ... "<<endl;
    for(int k=0; k<2;k++){
        for(int i=0; i< edges[0][0]->input_weight.size()-1 ; i++){ zero += "0";}
        if(k==1){ zero[0] ='1';}
//        cout<<zero<<endl;
        input_lib.push_back(zero);
        zero.clear();
    }

}

vector <string> Path_Judge::decide(AssertionRule& asrt, vector <string> input_lib, vector< vector<Edge *> >& edges){

        while ( trigger == 0){
            int i = target_assertion(asrt);

            for( int j = 0 ; j < edges.size() && trigger == 0 ; j++ ){
                if ( edges[j][0] -> node[0]->id == 0 && input_lib.size() == 0){
                    initializer(input_lib, edges);
                }

                end     =    asrt.rules[i]->delay_end;
                start   = (  end > edges[j].size()+1 ? edges[j].size() - end : 0 );
                R_F     = (  asrt.rules[i] -> req_action == "rose" ? '0' : '1');
                nR_F     = (  asrt.rules[i] -> req_action == "rose" ? '1' : '0');
                bit     =    asrt.rules[i] -> req_number;
                cout<<"targetted assertion rule is = "<<i<< endl;
                cout<<"the request is "<<asrt.rules[i]->req_action<< "<" <<asrt.rules[i]->req_type<<"["<<bit<<"]"<<">"<<endl;



                if ( asrt.rules[i]->req_type[0] == 'o'){ // case : output
                    for ( int E = start ; E < edges[j].size()-1 && trigger == 0 ; E ++) {

                        if ( edges[j][E] -> output_weight[bit]   ==  R_F &&
                             edges[j][E+1] -> output_weight[bit] == nR_F    ){
                             path_maker( j, input_lib, edges);
                        }

                    }
                }

                else if ( asrt.rules[i]->req_type[0] == 'i'){ // case : input
                    for ( int E = start ; E < edges[j].size()-1 && trigger == 0 ; E ++) {
                        // case : x --> 0 or 1 || 0 or 1 --> x
                        if ( edges[j][E] -> input_weight[bit] == R_F && edges[j][E+1]-> input_weight[bit] == 'x'  ||
                             edges[j][E] -> input_weight[bit] == 'x' && edges[j][E+1]-> input_weight[bit] == nR_F   ){

                                edges[j][E] -> input_weight[bit] = R_F ;    // x --> 0 or 1
                                edges[j][E+1] -> input_weight[bit] = nR_F ; // 0 or 1 --> x
                                path_maker( j, input_lib, edges);
                        }

                        else if ( edges[j][E] -> input_weight[bit] == 'x' && edges[j][E+1]-> input_weight[bit] == 'x'   ){
                            edges[j][E] -> input_weight[bit] = ( asrt.rules[i] -> req_action == "rose" ? '0' : '1');
                            edges[j][E+1] -> input_weight[bit] = ( asrt.rules[i] -> req_action == "rose" ? '1' : '0' );
                            path_maker( j, input_lib, edges);
                        }

                    }
                }


                else{
                    cout<<"error when reading req_signal!"<<endl;
                }

            }   // for each seq in edges

            if ( trigger == 0){
                cout<<"can't trigger assertion rule = "<<i<<", try next..."<<endl;
                NOT_triggered = i;
            }
            if ( NOT_triggered == asrt.rules.size()-1){
                cout<<"Can't trigger any assertion in current path config, go random walk for path ";
                int j = (rand() % static_cast<int>(edges.size() ));
                cout<<j<<endl;
                path_maker( j, input_lib, edges);
            }

        }   // while
        return  in_weight_seq;
}   // decide ()



vector <string> Path_Judge::out_weight_generator(){
    return out_weight_seq;
}
