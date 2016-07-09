/**
* 
*/
#include <inc_libs.h>
#include "linkedlist.h"

using namespace alg;

const int MAX_ELEMENTS = 10005;

int main() {
	
	LinkedList<int> *list = new LinkedList<int>(), 
	*list2 = new LinkedList<int>();
	list->insert_to_tail(12);
	list2->insert_to_tail(14);
	list = list2;	
	return 0;
}