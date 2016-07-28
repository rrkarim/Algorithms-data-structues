/**
*   100093C - Codeforces
*   Lazy propagation
*/
#include <bits/stdc++.h>
#define MAXN 100002
#define INF 2000000
typedef long long ll;
using namespace std;
const ll mod = 12345;
const ll _mod = 23456;

ll a[MAXN + 20];
// tmin[4 * MAXN], tmax[4 * MAXN];
ll t[4 * MAXN];
int dz[4 * MAXN];
int n;


void push(int v) {
    if(t[v] != -1) {
        t[v*2] = t[v*2+1] = t[v];

        t[v] = -1;
    }
}

ll sum_query(int v, int tl, int tr, int l, int r) {
    if(l > r) return 0;
    if(l == tl && r == tr && t[v] != -1) {
        return 1ll*(r - l + 1)*t[v];
    }
    else {
        push(v);
        int tm = (tl + tr) >> 1ll;
        return sum_query(v*2,tl,tm,l,min(tm,r)) + sum_query(v*2+1,tm+1,tr,max(tm+1,l),r);
    }
}

void update(int v, int tl, int tr, int l, int r, const ll &color) {
    //cout << tl << " " << tr << endl;
    if(l > r) return;
    if(l == tl && r == tr) {
        //cout << l << " " << r << endl;
        t[v] = color;
    }
    else {
        push(v);
        int tm = (tl + tr) >> 1ll;
        update(v*2, tl, tm, l, min(tm, r), color);
        update(v*2+1, tm+1, tr, max(tm+1,l), r, color);
    }
}

ll get (int v, int tl, int tr, int pos) {
	if (tl == tr) return t[v];
	push (v);
	int tm = (tl + tr) / 2;
	if (pos <= tm)
		return get (v*2, tl, tm, pos);
	else
		return get (v*2+1, tm+1, tr, pos);
}

int main() {
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);
    int n, l , r;
    ll x;
    //for(int i = 0; i < 4*MAXN; ++i) t[i] = -1;
    int q; cin >> n >> q;
    char ch;
    for(int i = 0; i < q; ++i) {

        scanf("\n%c", &ch);

        if(ch == 'A') {

            scanf("%d%d%I64d",&l,&r,&x);
            update(1,0,n-1,l-1,r-1,x);

        }
        else {

            scanf("%d%d",&l,&r);
            printf("%I64d\n", sum_query(1,0,n-1,l-1,r-1));

        }

    }

}