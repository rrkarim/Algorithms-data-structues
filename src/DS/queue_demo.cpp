/**
* 
*/
#include <inc_libs.h>
#include "queue.h"
#include <time.h>

using namespace alg;
using namespace std;

const int MAX_ELEMENTS = 10005;

int main() {
	srand (time(NULL)); //init random

	Queue<int> q0, q1;
	for(int i = 0; i < 10; ++i) q0.pushBack(rand() % 30); // generate 10 random elements

	for(Queue<int>::Iterator it = q0.begin(); it != q0.end(); ++it) {
		cout << *it << endl;
	}

	return 0;
}