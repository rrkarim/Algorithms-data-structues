/**
* 
*/
#include <inc_libs.h>
#include "linkedlist.h"

using namespace alg;

const int MAX_ELEMENTS = 10005;

int main() {

	LinkedList<int> list;
	LinkedList<int> list2;
	list.insert_to_tail(13);
	list.insert_to_tail(14);	
	list.insert_to_tail(15);
	list.insert_to_tail(18);
	list.insert_by_position(17, 0);

	list.remove_by_position(0);
	
	list.traverse_print();



	list2.insert_to_tail(33);
	list2.insert_to_tail(34);

	list = list2;
	list.traverse_print();	

	return 0;
}