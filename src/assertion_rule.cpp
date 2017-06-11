#include "assertion_rule.h"

Rule::Rule(int num, string req, string delay, string ack) {
	id = num;
	
	int temp = req.find("[");
	req_action = req.substr(0, 4);
	req_type = req.substr(5, temp-5);
	req_number = atoi(req.substr(temp+1, req.length()-temp-3).c_str());
	
	temp = delay.find(":");
	delay_start = atoi(delay.substr(1, temp-1).c_str());
	delay_end = atoi(delay.substr(temp+1, delay.length()-temp-2).c_str());
	
	temp = ack.find("[");
	ack_action = ack.substr(0, 4);
	ack_type = ack.substr(5, temp-5);
	ack_number = atoi(ack.substr(temp+1, ack.length()-temp-3).c_str());
	
	flag = true;
}

void Rule::ruleChecker(vector<string>& in_weight_seq, vector<string>& out_weight_seq) {	
	// trigger
	vector<int> clock;
	if(req_type == "in") {
		if(req_action == "rose") {
			for(int i=0;i<in_weight_seq.size();i++) {
				if(i != 0 && (in_weight_seq[i][req_number] == '1') && (in_weight_seq[i-1][req_number] == '0'))
					clock.push_back(i);
			}
		}
		else {
			for(int i=0;i<in_weight_seq.size();i++) {
				if(i != 0 && (in_weight_seq[i][req_number] == '0') && (in_weight_seq[i-1][req_number] == '1'))
					clock.push_back(i);
			}
		}
	}
	else {
		if(req_action == "rose") {
			for(int i=0;i<out_weight_seq.size();i++) {
				if(i != 0 && (out_weight_seq[i][req_number] == '1') && (out_weight_seq[i-1][req_number] == '0'))
					clock.push_back(i);
			}
		}
		else {
			for(int i=0;i<out_weight_seq.size();i++) {
				if(i != 0 && (out_weight_seq[i][req_number] == '0') && (out_weight_seq[i-1][req_number] == '1'))
					clock.push_back(i);
			}
		}
	}
	
	// remaining rule
	for(int i=0;i<clock.size();i++) {
		// rules must go to Cycle node
		if(in_weight_seq.size() - clock[i] < delay_start) {
			flag = false;
			break;
		}	
		// rules may be expired or failed
		else { 
			int temp = clock[i] + delay_start;
			if(ack_type == "in") {
				if(ack_action == "rose") {
					for(int j=0;j<=delay_end-delay_start;j++) {
						if((in_weight_seq[temp+j][ack_number] == '1') && (in_weight_seq[temp+j-1][ack_number] == '0'))
							break;
						else
							flag = false;				
					}
				}
				else {
					for(int j=0;j<=delay_end-delay_start;j++) {
						if((in_weight_seq[temp+j][ack_number] == '0') && (in_weight_seq[temp+j-1][ack_number] == '1'))
							break;
						else
							flag = false;
					}
				}
			}
			else {
				if(ack_action == "rose") {
					for(int j=0;j<=delay_end-delay_start;j++) {
						if((out_weight_seq[temp+j][ack_number] == '1') && (out_weight_seq[temp+j-1][ack_number] == '0'))
							break;
						else
							flag = false;				
					}
				}
				else {
					for(int j=0;j<=delay_end-delay_start;j++) {
						if((out_weight_seq[temp+j][ack_number] == '0') && (out_weight_seq[temp+j-1][ack_number] == '1'))
							break;
						else
							flag = false;				
					}
				}
			}			
		}
	}
}


void AssertionRule::addAsertionRules(int num, string req, string delay, string ack) {	
	Rule* r = new Rule(num, req, delay, ack);
	rules.push_back(r);
}

bool RuleCompByID( const Rule* A, const Rule* B ){
	if ( A->id < B->id ) return true;
    else return false;
}

void AssertionRule::sortAssertionById() {
    sort(rules.begin(), rules.end(), RuleCompByID);
}

void AssertionRule::displayAssertionRules() {
	for(int i=0; i<rules.size(); i++) {
		cout << "Rule " << rules[i]->id << ": \t";
		cout << rules[i]->req_action << "(" << rules[i]->req_type << "[" << rules[i]->req_number << "]) \t";
		cout << "[" << rules[i]->delay_start << ":" << rules[i]->delay_end << "] \t";
		cout << rules[i]->ack_action << "(" << rules[i]->ack_type << "[" << rules[i]->ack_number << "]) \n";
	}
}
