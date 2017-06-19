#include "fsm_parser.h"
#include "graph.h"
#include "fsm_parser.h"

using namespace std;

int main(int argc, char **argv) {

	vector < vector <int> > adj_list;
	vector < vector <string> > input_list;
	vector < vector <string> > output_list;

	Graph fsm;
	char* const test = "shit";
	
	fsm_parser(argv[1], adj_list, input_list, output_list);
	fsm.initializeWithVector(adj_list, input_list, output_list);
	fsm.sortNodesByID();
	fsm.displayNodesAndEdges();
	fsm.convertFSMtoDot("");

	return 0;
}
