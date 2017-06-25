#ifndef ASSERTION_RULE_H
#define ASSERTION_RULE_H

#include <cstring>
#include <vector>
#include <algorithm>

class Rule {

	public:
		Rule(int num, string req, string delay, string ack);
		int id;
		string req_action; // either rose or fell
		string req_type; // either in or out
		int req_number; // eg. [0]
		int delay_start;
		int delay_end;
		string ack_action;
		string ack_type;
		int ack_number;
		bool flag;
		void ruleChecker(vector<string>& in_weight_seq, vector<string>& out_weight_seq);
//		bool inPathTrigger(vector<string> in_weight_seq, vector<string> out_weight_seq);
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
