/**
	Dijkstra algorithm
	Rasul Kerimov (CoderINusE)
*/
#include <bits/stdc++.h>
#define MAXN 200005
#define INF 2000000000
#define _INF -20000000
#define RANDOM_INIT()	srand(time(NULL))
#define RANDOM(L, R)	(L + rand() % ((R) - (L) + 1)) // gen a random integer in [L, R]

typedef long long ll;
using namespace std;


vector<vector< pair <int, int> > > g;
int n, m, u, v, w;

vector< int > dijkstra(const int &start) {
	vector< int > d(n + 1, INF);
	d[start] = 0;
	priority_queue<pair<int,int>> q;
	q.push({0, start});

	while(!q.empty()) {
		int value = q.top().second;
		int dist = -q.top().first;
		q.pop();

		if(dist > d[value]) continue;
		for(int i = 0; i < g[value].size(); ++i) {
			int to = g[value][i].first, dist_temp = g[value][i].second;
			if(d[value] + dist_temp < d[to]) {
				d[to] = d[value] + dist_temp;
				q.push({-d[to], to});
			}
		}
	}
	return d;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	g.resize(n + 1);

	for(int i = 0; i < m; ++i) {
		cin >> u >> v >> w;
		g[u].push_back({v, w});
	}

	vector<int> d = dijkstra(1);
    for(int i = 1; i <= n; ++i) cout << d[i] << endl;
}
