/**
* 
*/
#include <inc_libs.h>
#include "binary_search_tree.h"
#include <vector>
using namespace alg;

const int MAX_ELEMENTS = 10005;

int main() {
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	BST<int, int>* t = new BST<int, int>(v);
	t->print_tree();
	return 0;
}