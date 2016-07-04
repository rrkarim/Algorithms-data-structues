/**
*/
#include <inc_libs.h>
#include "graph_operations.h"
#include <dijkstra.h>

using namespace alg;

int main() {
	vii<int> g = alg::Graph_Op<int>().rand_directed(10);
	vi<int> d = DJpath<int>().run(g, 0);
}
