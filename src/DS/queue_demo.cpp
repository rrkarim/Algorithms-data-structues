/**
* 
*/
#include <inc_libs.h>
#include "queue.h"
#include <time.h>
#include <list>

using namespace alg;
using namespace std;

const int MAX_ELEMENTS = 10005;

int main() {
	srand (time(NULL)); //init random
	Queue<int> q0, q1;
	list<int> l;
	for(int i = 0; i < 10; ++i) q0.pushBack(rand() % 30); // generate 30 random elements

	for(Queue<int>::Iterator it = q0.begin(); it != q0.end(); ++it) {
		cout << *it << endl;
	}

	//copy(q0.begin(), q0.end(), back_inserter(l));


	return 0;
}