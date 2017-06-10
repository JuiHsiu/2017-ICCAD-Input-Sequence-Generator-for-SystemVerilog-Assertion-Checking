#include "assertion_rule.h"

Rule::Rule(int num, string req, string delay, string ack) {
	id = num;
	req_action = req.substr(0, 4);
	req_signal = req.substr(5, req.length()-6);
	int temp = delay.find(":");
	delay_start = atoi(delay.substr(1, temp-1).c_str());
	delay_end = atoi(delay.substr(temp+1, delay.length()-temp-2).c_str());
	ack_action = ack.substr(0, 4);
	ack_signal = ack.substr(5, ack.length()-6);
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
		cout << rules[i]->req_action << "(" << rules[i]->req_signal << ") \t";
		cout << "[" << rules[i]->delay_start << ":" << rules[i]->delay_end << "] \t";
		cout << rules[i]->ack_action << "(" << rules[i]->ack_signal << ")";
		cout << endl;
	}
}
