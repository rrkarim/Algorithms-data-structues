#ifndef __GRAPH_OPERATIONS__
#define __GRAPH_OPERATIONS__

#include <vector>
#include <stdlib.h>
#include <iostream>
//#include <math_numbers.h>

namespace alg {
	
	// Multi-template class structure

	struct nothing {};

	template <typename T, typename TW = nothing>
	class Graph_Op;

	template <typename T>
	class Graph_Op<T, nothing> {
	    public:
		
		// return random directed unweighted graph
		static vii<T> rand_directed(const int &value) {
			vii<T> ret;
			ret.resize(value);

			// FIX use boost libriary
			srand(0);
			//**

			for(int i = 0; i < value; ++i) {
				for(int j = i + 1; j < value; ++j) {
					// 33% connected graph
					int x = rand() % 3;
					if(!x) {
						ret[i].push_back(j);
					}
				}
			}

			return ret;

		}

		static void print_graph(const vii<T>& temp_graph) {
           	for(int i = 0; i < temp_graph.size(); ++i) {
                for(int j = 0; j < temp_graph[i].size(); ++j) {
                    std::cout << i << " " << temp_graph[i][j] << std::endl;
                }
            }
		}
	};
	template <typename T, typename TW>
	class Graph_Op {
		public:
			// return random directed weighted graph
			static viiw<T, TW> rand_weighted_directed(const int &value) {
			viiw<T, TW> ret;
			ret.resize(value);

			// FIX ***
			srand(0);
			//**

			for(int i = 0; i < value; ++i) {
				for(int j = i + 1; j < value; ++j) {
					int x = rand() % 3;
					if(!x) {
						int value = rand() % 100;
						ret[i].push_back({j, value});
					}
				}
			}

			return ret;

		}

	};
}

#endif
