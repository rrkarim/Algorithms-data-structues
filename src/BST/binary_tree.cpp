/**
* 
*/
#include <inc_libs.h>
#include "binary_search_tree.h"

using namespace alg;

const int MAX_ELEMENTS = 10005;

int main() {
	
	BST<int, int> t;

	t.insert(1, 100);
	t.insert(2, 100);
	t.insert(3, 50);
	t.insert(4, 200);

	t.print_helper();
	
	return 0;
}