/**
    100246C
*/
#include <bits/stdc++.h>
#define MAXN 1000002
using namespace std;
typedef long long ll;

ll a[MAXN], t[MAXN], b[MAXN];
map <ll, int> M;

void update_tree(int i, const int &n, const ll &new_val) {
    for(i; i < n; i = (i | (i + 1))) t[i] += new_val;
}

ll sum_tree(int k, const int &n) {
    ll sum = 0;
    for(; k >= 0; k = (k & (k + 1)) - 1) sum += t[k];
    return sum;
}

ll get_sum(const int &l, const int &r, const int &n) {
    return sum_tree(r, n) - sum_tree(l - 1, n);
}
ll get_inverse(const int &n) {
    ll res = 0;
    for(int i = 0; i < n; ++i) {
        res += i - get_sum(0, M[a[i]] - 1, n);
        update_tree(M[a[i]], n, 1);
    }
    return res;
}

int main() {
    freopen("inverse.in", "r", stdin);
    freopen("inverse.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    int n, m, td, l, r, x; ll y;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
        b[i] = a[i];
    }
    sort(b, b + n);
    for(int i = 0; i < n; ++i) M[b[i]] = i + 1;
    cout << get_inverse(n) << endl;
}