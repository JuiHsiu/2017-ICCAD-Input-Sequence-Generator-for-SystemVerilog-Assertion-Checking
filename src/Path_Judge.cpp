// **************************************************************************
// File       [ main.cpp ]
// Author     [ Michael Lee ]
// Synopsis   [ This file decides a path between two cycles and return that path ]
// Date       [ 2017/06/10 created ]
// **************************************************************************

#include "Path_Judge.h"


Path_Judge::Path_Judge(AssertionRule asrt)
{
    trigger = 0;
    NOT_triggered = -1;
    cleaner = 0;
    Max_delay(asrt);
    random = 0;
}

int Path_Judge::target_assertion(AssertionRule asrt){
    for(int i = NOT_triggered+1; i < asrt.rules.size() ; i++){
        if ( asrt.rules[i] -> flag == true  ){
            return i;
        }

		if(i == asrt.rules.size()-1){
			if(NOT_triggered == -1){
            	cout<<"all assertions already failed!"<<endl;
            	trigger = 1;
            	return 0;
        	}
        	else{
        		random = 1;
			}


        }

    }
}

void Path_Judge::path_maker( int seq , AssertionRule& asrt,vector<string>& input_lib,  vector< vector<Edge *> > edges, bool cBTWc, bool Lock_In){
        int edge = 0;
        //cout<<" decideIndex = "<<decideIndex<<endl;

            cout<<"unprocessed input was"<<endl;
            for (int i =0 ;i < edges[seq].size() ; i++){
                cout<<edges[seq][i]->input_weight<<"    ";
            }
            cout<<"\n"<<endl;

            while( edge < edges[seq].size()){ // before the end of edge sequence

                for( int bit = 0; bit < edges[seq][edge]->input_weight.size(); bit++){ // check each bit on a edge
                    if ( edges[seq][edge]->input_weight[bit] == 'x' && Lock_In == 0 && cleaner == 0){
                            iPrev = input_lib[input_lib.size()-1];
                            copy_input_weight += (iPrev[bit+1] =='1'?'0':'1');
                            // edges[seq][edge]->input_weight[bit] = (iPrev[bit+1] =='1'?'0':'1');
                    }
                    else if ( edges[seq][edge]->input_weight[bit] == 'x' && Lock_In == 0 && cleaner == 1){
                            iPrev = input_lib[input_lib.size()-1];
                            copy_input_weight += (iPrev[bit+1] =='1'?'1':'0');
                    }
                    else if ( edges[seq][edge]->input_weight[bit] == 'x' && Lock_In == 1 ){
                            if ( edge == decideIndex && bit == target_bit){
                                copy_input_weight += desireVal_1;
                            }
                            else if ( edge == decideIndex+1 && bit == target_bit){
                                copy_input_weight += desireVal_2;
                            }
                            else {
                                iPrev = input_lib[input_lib.size()-1];
                                copy_input_weight += (iPrev[bit+1] =='1'?'0':'1');
                            }
                    }

                    else if ( edges[seq][edge]->input_weight[bit] == '1' ||
                              edges[seq][edge]->input_weight[bit] == '0'){

                        copy_input_weight += edges[seq][edge]->input_weight[bit];
                    }
                }
                // push this input or output weight
                //string dummy = edges[seq][edge]->input_weight;
                string dummy = "0"+copy_input_weight;
                input_lib.push_back(dummy);
                in_weight_seq.push_back(dummy);
                out_weight_seq.push_back(edges[seq][edge]->output_weight);
                edge++;
                copy_input_weight.clear();
            }
            if (cBTWc == 1){
                cycle_path_maker( asrt, edges[seq], input_lib );
            }
            trigger = 1;
}

void Path_Judge::initializer(vector<string>& input_lib , vector< vector<Edge *> > edges){
    cout<<"initializing ... "<<endl;
    for(int k=0; k<2;k++){
        for(int i=0; i<= edges[0][0]->input_weight.size() ; i++){ zero += "0";}
        if(k==1){ zero[0] ='1';}
//        cout<<zero<<endl;
        input_lib.push_back(zero);
        in_weight_seq.push_back(zero);
        zero.clear();
    }
    out_weight_seq.push_back("x");
    out_weight_seq.push_back(edges[0][0]->output_weight);
}

void Path_Judge::decide(AssertionRule& asrt, vector <string>& input_lib, vector< vector<Edge *> > edges){
        cout<<"decide() is called\n"<<endl;

        // reset the previous outcomes
        out_weight_seq.clear();
        in_weight_seq.clear();
        trigger = 0;
        NOT_triggered = -1;
        random = 0;

        while ( trigger == 0){

            int i = target_assertion(asrt);
            	bit     =    asrt.rules[i] -> req_number;
			    cout<<"targetted assertion rule is = "<<asrt.rules[i]->id<< endl;
                cout<<"the request is "<<asrt.rules[i]->req_action<< "<" <<asrt.rules[i]->req_type<<"["<<bit<<"]"<<">"<<endl;
//                cout<<" the status of remaining assertions are:"<<endl;
//                for ( int i =0 ; i < asrt.rules.size() ; i++){
//        			cout<<"asrt.rules "<<asrt.rules[i]->id<<" is " <<asrt.rules[i]-> flag <<endl;
//                    cout<<"asrt.rules.size() = "<<asrt.rules.size()<<endl;
//        		}

				// adjust the bit
				out_bit = edges[0][0]->output_weight.size()-bit-1;
				bit = edges[0][0]->input_weight.size()-bit-1;
//                cout<<"edge size = "<<edges.size()<<" and trigger = "<<trigger<<endl;
            for( int j = 0 ; j < edges.size() && trigger == 0 ; j++ ){
                if ( edges[j][0] -> node[0]->id == 0 && input_lib.size() == 0){
                    initializer(input_lib, edges);
                }
//				cout<<" bit = "<<bit<<" out_bit = "<<out_bit<<endl;
                end     =    asrt.rules[i]->delay_end;
                start   = (  end < edges[j].size()+1 ? edges[j].size() - end : 0 );
                R_F     = (  asrt.rules[i] -> req_action == "rose" ? '0' : '1');
                nR_F     = (  asrt.rules[i] -> req_action == "rose" ? '1' : '0');




                if ( asrt.rules[i]->req_type[0] == 'o'){ // case : output
                    for ( int E = start ; E < edges[j].size()-1 && trigger == 0 ; E ++) {

                        if ( edges[j][E] -> output_weight[out_bit]   ==  R_F &&
                             edges[j][E+1] -> output_weight[out_bit] == nR_F    ){
                             path_maker( j, asrt,input_lib, edges,1,1);
                        }
                    }
                }

                else if ( asrt.rules[i]->req_type[0] == 'i'){ // case : input
                    for ( int E = start ; E < edges[j].size()-1 && trigger == 0 ; E ++) {
                        // case : x --> 0 or 1 || 0 or 1 --> x
                        if ( edges[j][E] -> input_weight[bit] == R_F && edges[j][E+1]-> input_weight[bit] == 'x'  ||
                             edges[j][E] -> input_weight[bit] == 'x' && edges[j][E+1]-> input_weight[bit] == nR_F   ){
                               // edges[j][E] -> input_weight[bit] = R_F ;    // x --> 0 or 1
                               //edges[j][E+1] -> input_weight[bit] = nR_F ; // 0 or 1 --> x
                               desireVal_1 = R_F;
                               desireVal_2 = nR_F;
                               decideIndex = E;
                               target_bit = bit;
                               path_maker( j, asrt,input_lib, edges,1,1);
                        }

                        else if ( edges[j][E] -> input_weight[bit] == 'x' && edges[j][E+1]-> input_weight[bit] == 'x'   ){
                            //edges[j][E] -> input_weight[bit] = ( asrt.rules[i] -> req_action == "rose" ? '0' : '1');
                            //edges[j][E+1] -> input_weight[bit] = ( asrt.rules[i] -> req_action == "rose" ? '1' : '0' );
                            desireVal_1 = ( asrt.rules[i] -> req_action == "rose" ? '0' : '1');
                            desireVal_2 = ( asrt.rules[i] -> req_action == "rose" ? '1' : '0' );
                            decideIndex = E;
                            target_bit = bit;
                            path_maker( j, asrt,input_lib, edges,1,1);
                        }

                    }
                }


                else{
                    cout<<"error when reading req_signal!"<<endl;
                }

            }   // for each seq in edges
            if ( trigger == 0){
                cout<<"can't trigger assertion rule = "<<asrt.rules[i]->id<<", try next..."<<endl;
                NOT_triggered = i;
            }
            if ( random == 1){
                cout<<"Can't trigger any assertion in current path config, go random walk for path ";
                int j = (rand() % static_cast<int>(edges.size() ));
                cout<<j<<endl;
                path_maker( j, asrt,input_lib, edges,1,0);
            }

        }   // while
}   // decide ()



vector <string> Path_Judge::out_weight_generator(){
    return out_weight_seq;
}

vector <string> Path_Judge::in_weight_generator(){
    return in_weight_seq;
}


void Path_Judge::Max_delay( AssertionRule asrt ){
    max = -1;
    for ( int i =0; i < asrt.rules.size() ; i++){
        max = (asrt.rules[i]->delay_end > max ? asrt.rules[i]->delay_end : max);
    }
    cout<<"max = "<<max<<endl;
}

/*
void Path_Judge::Max_delay( AssertionRule asrt, vector<string> in_weight_seq, vector<string> out_weight_seq){
    cout<<"max delay is called \n"<<endl;
    max = -1;
    for ( int i =0 ; i < in_weight_seq.size() ; i++){
        for(int j = 0; j < asrt.rules.size() ; j++){
            if ( asrt.rules[j] -> flag == true  &&
                 asrt.rules[j]->inPathTrigger(in_weight_seq, out_weight_seq) == 1){
//                 cout<<"asrt.rules[j] "<<asrt.rules[j]->id<<" is triggered "<<endl;
                 max = (asrt.rules[j]->delay_end > max ? asrt.rules[j]->delay_end : max);
            }

        }
    }
}
*/

void Path_Judge::assertion_cleaner(AssertionRule asrt,vector< vector<Edge *> >& tmp_edge_path , vector<Edge *>  selected_edges, vector <string>& input_lib ){
    int last = selected_edges.size()-1;
    int cSelf = selected_edges[last]-> node[1]->edge_out.size();
    int repeat = 0;
    bool terminate = 0;
    cleaner = 1;
    cout<<"assertion cleaner is called "<<endl;
//    cout<<" the end point is "<<selected_edges[last]-> node[1]->id<<endl;

    for(int i=0; i < cSelf && terminate == 0; i++){
        if ( selected_edges[last]->node[1]->edge_out[i]->node[1]->id ==
             selected_edges[last]->node[1]->id){
             while ( repeat < max ){
                  tmp_edge_path[0].push_back(selected_edges[last]->node[1]->edge_out[i]);
                  repeat++;
             }
             path_maker(0 , asrt ,input_lib, tmp_edge_path, 0,0 );
             tmp_edge_path[0].clear();
             terminate = 1;
             cleaner =0;
        }
    }
};

void Path_Judge::trigger_in_cycle(AssertionRule asrt,vector< vector<Edge *> >& tmp_edge_path , vector<Edge *>  selected_edges, vector <string>& input_lib){
    cout<<"trigger in cycle is called "<<endl;
    int last = selected_edges.size()-1;
    int cSelf = selected_edges[last]-> node[1]->edge_out.size();
    for(int i=0; i < cSelf ; i++){
        if (selected_edges[last]->node[1]->edge_out[i]->node[1]->id ==
        selected_edges[last]->node[1]->id){
            tmp_edge_path[0].push_back(selected_edges[last]->node[1]->edge_out[i]);
        }
    }
    tmp_in_start = in_weight_seq.size();
    path_maker(0 , asrt, input_lib, tmp_edge_path, 0, 0);
    tmp_edge_path[0].clear();
}

void Path_Judge::cycle_path_maker( AssertionRule asrt, vector<Edge *>  selected_edges, vector <string>& input_lib ){
    vector< vector<Edge *> > tmp_edge_path;
    for (int y = 0; y < 1 ; y++){
        tmp_edge_path.push_back(vector<Edge *> {});
    }
    //Max_delay(asrt, in_weight_seq,out_weight_seq);
    assertion_cleaner(asrt,tmp_edge_path,selected_edges,input_lib);

    trigger_in_cycle(asrt,tmp_edge_path,selected_edges, input_lib);

    vector <string> tmp_input_seq;
    vector <string> tmp_output_seq;

    for (int i = tmp_in_start ; i < in_weight_seq.size() ; i++){
        tmp_input_seq.push_back(in_weight_seq[i]);
        tmp_output_seq.push_back(out_weight_seq[i]);
    }

    //Max_delay(asrt,tmp_input_seq,tmp_output_seq);
    assertion_cleaner(asrt,tmp_edge_path,selected_edges,input_lib);
    tmp_input_seq.clear();
    tmp_output_seq.clear();
}

