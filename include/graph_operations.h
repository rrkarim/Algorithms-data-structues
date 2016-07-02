#ifndef __GRAPH_OPERATIONS__
#define __GRAPH_OPERATIONS__

template <typename T>
using vii = std::vector< vector<T> >;

namespace alg {
	template <typename <T>>
	class Graph_Op {
		// return random undirected graph
		static vii rand_directed(const int &value) {
			vii ret;
			ret.resize(value);

			// FIX ***
			srand(time(NULL));
			//**

			for(int i = 0; i < value; ++i) {
				for(int j = i + 1; j < value; ++j) {
					int x = rand() % 3;
					if(!x) {
						ret[i].push_back(j);
					}
				}
			}

			return ret;

		}
	};

}

#endif