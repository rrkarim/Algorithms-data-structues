/**
    Rasul Kerimov (CoderINusE)
*/
#include <bits/stdc++.h>
#define MAXN 100005
#define INF 2e18
#define _INF -20000000

typedef long long ll;
using namespace std;
int n, m, t[MAXN + 2], d[MAXN + 2], tot, tmp;
ll ans;
int hor_used[10], ver_used[10], diag1_us[20], diag2_us[20];
int us[10][10];
int res = 0;
void f(int k, const int &n) {
    if(k == n) {
        res += 1; 
        return;
    }

    int vi[100], vi2[100];
    int len = 0;
    for(int i = 0; i < n; ++i) {
            if(hor_used[i]) continue;
            for(int j = 0; j < n; ++j) {
                if(us[i][j]) continue;

                int diag = (n - i - 1) + j;
                if(!hor_used[i] && !ver_used[j] && !diag1_us[i + j] && !diag2_us[diag]) {

                    hor_used[i] = 1, ver_used[j] = 1;
                    diag1_us[i + j] = 1, diag2_us[diag] = 1;

                    f(k + 1, n);

                    us[i][j] = 1, vi[len] = i, vi2[len] = j;
                    len += 1;

                    hor_used[i] = 0, ver_used[j] = 0;
                    diag1_us[i + j] = 0, diag2_us[diag] = 0;
                }

            }

        }
        for(int i = 0; i < len; ++i) us[vi[i]][vi2[i]] = 0;
    }
    int totalNQueens(int n) {
        f(0, n);
        return res ;
    }

int main() {
    cout << totalNQueens(9)<< endl;
}
