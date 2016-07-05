#ifndef __DIJKSTRA__
#define __DIJKSTRA__

#include <inc_libs.h>
#include <queue>
namespace alg {
	template <typename T, typename TW>
	class DJpath {
		public:
			static vi<T> run(const viiw<T, TW> & g, const T init) {
				int n = g.size();
				vi<T> d(n, PINF<int>::max()); // use alias template <T> declared in inc_libs
				d[ init ] = 0;

				std::priority_queue<std::pair <TW, T>> q;
				q.push({0, init}); // push first vertex
				while(!q.empty()) {
					T value = q.top().second;
					TW cur_d = -q.top().first;
					q.pop();
					if(cur_d > d[value]) continue;
					
					for(size_t i = 0; i < g[value].size(); ++i) {
						T to = g[value][i].first;
						TW len = g[value][i].second;
						if(d[value] + len < d[to]) {
							d[to] = d[value] + len;
							q.push({-d[to], to});
						}
					}
				}
				return d;
			}
	};
}

#endif