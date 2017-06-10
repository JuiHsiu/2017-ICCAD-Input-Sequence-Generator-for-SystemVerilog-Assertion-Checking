/*
Filename: assertion_parser.cpp
Author:  Brady Huang
Description: this function extract the assertion rules in 3 string vectors: con, con_delay, res
Revision:   V.2017.5.17  
*/
#include "assertion_parser.h"
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

//void collect_assertion(char* filename)
void collect_assertion(char *filename, vector<string>& con, vector<string>& con_delay, vector<string>& res)
{
	bool DEBUG = 0;
    ifstream file(filename);
    string str, con_slice, res_slice, con_delay_slice; 
    // vector<string> con, res, con_delay;
    // enum Condition{rose, fell, in, out};  
    size_t token_1, b_con1, e_con1, b_con2, e_con2, b_time, e_time;

    while (!file.eof())
    {
    	getline(file, str);
    	//cout << str << endl;
    	token_1 = str.find("(posedge clk)");
    	if (token_1!=string::npos)
    	{
    		str = str.substr(token_1);
    		// cout << str << endl;

       		b_con1 = str.find("$");
       		e_con1 = str.find("|");
    		con_slice = str.substr(b_con1 + 1, e_con1 - b_con1 - 1);
    		// cout << con_slice << " ";
    		con.push_back(con_slice);

    		b_time = str.find("##");
       		e_time = str.find(" $", b_con1 + 1);
    		con_delay_slice = str.substr(b_time + 2, e_time - b_time - 1);
    		// cout << con_delay_slice << " ";
    		con_delay.push_back(con_delay_slice);

    		b_con2 = str.find("$", b_con1 + 1);
    		e_con2 = str.find("))", b_con1 + 1);
    		res_slice = str.substr(b_con2 + 1, e_con2 - b_con2);
    		// cout << res_slice << endl;
    		res.push_back(res_slice);
    		

    	}
    }
    file.close();
    
	if (DEBUG)
	{
		for (int i = 0; i < con.size(); i++ )
			cout << con[i] << " " << con_delay[i] << " " << res[i] << endl;
	}
    // return 0;
}

