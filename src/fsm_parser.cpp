// **************************************************************************
// File       [ fsm_parser.cpp ]
// Author     [ Michael ]
// Synopsis   [ Read the nodes of the finite machine, and the input/output corresponding to a node]
// Date       [ 2017/05/15 created ]
// **************************************************************************
#include "fsm_parser.h"

void fsm_parser(char *filename, vector<vector<int> >& adj_list, vector<vector<string> >& input_list, vector<vector<string> >& output_list){
	fstream fin(filename);

    string str, num_str, lead_nd, input_str,output_str,cnnct_nd_str;
    int cnnct_nd = 0, tmp , num_nd, max_nd = 0, node;
    bool toggle = 0, flag = 0;

//    vector < vector <int> > adj_list;
//    vector < vector <string> > input_list;
//    vector < vector <string> > output_list;


    // find out the maxium node
    while( getline(fin,str) && !toggle) {
        int always      = str.find("always");
        int parameter   = str.find("parameter");

        if ( always > -1 )                                          // condition of ending while
            toggle = !toggle;

        if ( parameter > -1 ){                                      // condition of start reading
            flag = !flag;
            tmp = 11;                                               // set the condition so that "parameter" don't get read in
        }

        if (flag == 1 && str.length()>1 ){
            while(tmp != 0){                                        // read until the end of a line (
                num_str = str.substr(tmp,str.find("=",tmp)-tmp);    // extract the node number e.g. S6
                num_nd = atoi(num_str.c_str());                     // convert it to integer
                tmp = str.find("S",tmp)+1;                          // find next postion of node on the same line
                max_nd = (num_nd > max_nd ? num_nd : max_nd );      // compare if the new node is larger than the max
            }
            tmp = 1;                                                // reset the postion for next line
        }
    }

    // initialize the empty list
    for(int i =0 ;i<=max_nd;i++){
        adj_list.push_back(vector<int>{});
        input_list.push_back(vector<string>{});
        output_list.push_back(vector<string>{});
    }


    // main part for reading
    while(getline(fin,str)) {
         int pos_lead_nd    =   str.find("casex");
         int pos_input      =   str.find("'")+1;
         int pos_cnnct_nd   =   str.find("nstate=" , pos_input)+8;
         int pos_output     =   str.find("'" , pos_cnnct_nd)+1;

         if(pos_lead_nd>0){                                                     //"casex" found in this line
            lead_nd    =   str.substr(1,str.find(":")-1);
            node   =   atoi(lead_nd.c_str());
         }

         else if (pos_input > 1 && pos_cnnct_nd > 8 && pos_output > 1){         // this line matchs the description for input, connecting nodes and ouput

            input_str       =   str.substr(pos_input    ,str.find(":") - pos_input);
            output_str      =   str.substr(pos_output   ,str.find(";",pos_output) - pos_output);
            cnnct_nd_str    =   str.substr(pos_cnnct_nd ,str.find(";") - pos_cnnct_nd);
            cnnct_nd        =   atoi(cnnct_nd_str.c_str());

            adj_list[node].push_back(cnnct_nd);
            input_list[node].push_back(input_str);
            output_list[node].push_back(output_str);
         }
    }

//    cout<<"output_list.size() = "<<output_list.size()<<endl;
//    for(int i=0; i<output_list.size();i++){
//        cout<<"s"<<i<<endl;
//        for(int j=0; j<output_list[i].size();j++){
//            cout<<input_list[i][j]<<" s"<<adj_list[i][j]<<" "<<output_list[i][j]<<endl;
//        }
//        cout<<endl;
//    }


    fin.close();
    
//    return 0;
}

