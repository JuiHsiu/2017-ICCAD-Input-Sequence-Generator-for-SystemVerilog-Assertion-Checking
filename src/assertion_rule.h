#ifndef ASSERTION_H
#define ASSERTION_H

#include <cstring>
#include <vector>
#include <algorithm>

class Rule {
	
	public:
		Rule(int num, string req, string delay, string ack);
		int id;
		string req_action; // either rose or fell 
		string req_signal;
		int delay_start;
		int delay_end;
		string ack_action;
		string ack_signal;
		
};

class AssertionRule {
	
	public:
	vector<Rule *> rules;
	
	void addAsertionRules(int num, string req, string delay, string ack);
	void sortAssertionById();
	void displayAssertionRules();
};

#include "assertion_rule.cpp"
#endif
