/**
* 
*/
#include <inc_libs.h>
#include "stack.h"
#include <time.h>

using namespace alg;
using namespace std;

const int MAX_ELEMENTS = 10005;

int main() {
	srand (time(NULL)); //init random
	
	Stack<int> s0, s1;
	for(int i = 0; i < 10; ++i) s0.push(rand() % 30); // generate 10 random elements

	for(Stack<int>::Iterator it = s0.begin(); it != s0.end(); ++it) {
		cout << *it << endl;
	}

	return 0;
}