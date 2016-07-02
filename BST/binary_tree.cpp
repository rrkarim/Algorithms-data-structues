#include <stdio.h>
#include <time.h>

#include "binary_search_tree.h"

using namespace alg;
int main() {
	const int MAX_ELEMENTS = 10;
	int key[MAX_ELEMENTS];
	int value[MAX_ELEMENTS];
	BST<int, int> t;

	t.insert(1, 100);
	try {
		t.deleteKey(3);
	}
	catch(BST::BSTException& e) {
		
	}
	return 0;
}