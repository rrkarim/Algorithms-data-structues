#ifndef __GEN_TH_IN__
#define __GEN_TH_IN__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <vector>
#include <limits>
#define Max(a, b) ( (a > b) ? a : b )
#define Min(a, b) ( (a < b) ? a : b )
//#define PINF  2000000000000000
//#define MINF -2000000000000000
#define RANDOM_INIT()	srand(time(NULL))
#define RANDOM(L, R)	(L + rand() % ((R) - (L) + 1))

namespace alg {
	

	template <typename T>
	using vii = std::vector<std::vector<T>>;

	template <typename T>
	using vi = std::vector<T>;

	template <typename T, typename TW>
	using viiw = std::vector<std::vector< std::pair<T, TW> >>;

	template <typename T>
	using PINF = std::numeric_limits<T>;


	template <typename T>
	static void swap(T &x, T &y) {
		T temp = x;
		x = y;
		y = temp;
	}
}

#endif