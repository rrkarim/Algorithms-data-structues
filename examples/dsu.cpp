/**
    DSU
    e-olymp 325
    Rasul Kerimov (CoderINusE) 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000005;

vector <pair<int, int> > G [MAX];

int p [MAX];

int V, E;

struct edge
{
   int n1, n2;
   int w;
};

edge Q [MAX];
long long total_length;
bool selected[MAX];

int find_root(int N)
{
   if(p[N] == N) return N;
   else return p[N] = find_root(p[N]);
}

bool cmp(edge l, edge r) {
   return l.w < r.w;
}

int unionn(int i) {
    int r1 = find_root(Q[i].n1);
    int r2 = find_root(Q[i].n2);
    p[r1] = r2;
    return r1 != r2;
}
int main() {
   int a, b, w, s, f;
   scanf("%d%d", &V, &E);
   for(int i = 0; i < E; i ++) {
        scanf("%d%d%d", &a, &b, &w);
            Q[i].n1 = a;
            Q[i].n2 = b;
            Q[i].w = w;
   }
   for(int i = 1; i <= V; i ++) p[i] = i;
   sort(Q, Q + E, cmp);

   int selected_count = 0;
   int cur = 0, r1, r2;

   for(int i = 0; i < E; ++i) {

       unionn(i);

       if(find_root(1) == find_root(V)) {
            cout << Q[i].w << endl;
            break;
       }

   }
   return 0;
}