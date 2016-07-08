/**
* 
*/
#include <inc_libs.h>
#include "linkedlist.h"

using namespace alg;

const int MAX_ELEMENTS = 10005;

int main() {
	
	LinkedList<int> *list = new LinkedList<int>();
	list->insert(12);
	list->insert(13);
	list->insert(14);

	list->traverse_print();	
	return 0;
}