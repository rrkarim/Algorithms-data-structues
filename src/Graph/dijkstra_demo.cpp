/**
*/
#include <inc_libs.h>
#include "graph_operations.h"
#include <dijkstra.h>

using namespace alg;

int main() {
	viiw<int, int> g = alg::Graph_Op<int, int>().rand_weighted_directed(10);
	vi<int> d = DJpath<int, int>().run(g, 0);
}
