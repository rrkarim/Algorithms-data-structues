/**
* 
*/
#include <inc_libs.h>
#include "queue.h"

using namespace alg;
using namespace std;

const int MAX_ELEMENTS = 10005;

int main() {

	Queue<int> q;

	q.pushBack(3131);
	q.pushBack(31);
	q.pushBack(1);

	cout << q.popFront() << endl;
	

	/*

	list2.insert_to_tail(33);
	list2.insert_to_tail(34);

	list = list2;
	list.traverse_print();	
	
	*/
	return 0;
}