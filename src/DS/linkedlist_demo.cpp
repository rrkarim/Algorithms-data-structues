/**
	LinkedList implementation
	Iterator pattern
	Rasul Kerimov (CoderINusE) 
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
	//list.remove_by_position(0);
	list.swap_list();
	//list.traverse_print();

	for(LinkedList<int>::Iterator it = list.begin(); it != list.end(); ++it) {
		cout << *it << endl;
	}
	return 0;
}