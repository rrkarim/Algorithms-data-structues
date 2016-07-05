/**
	Dijkstra algorithm
	Rasul Kerimov (CoderINusE) 
*/
#include <inc_libs.h>
#include "graph_operations.h"
#include <dijkstra.h>

using namespace alg;

int main() {
	viiw<int, int> g = alg::Graph_Op<int, int>::rand_weighted_directed(10, 100);
	vi<int> d = DJpath<int, int>().run(g, 0);

	Graph_Op<int, int>::print_graph(g);

	//output distance vector
	for(int i = 0; i < d.size(); ++i) 
		std::cout << i << " " << d[i] << std::endl; 

}
