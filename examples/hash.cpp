/**
* DID YOU GET WHAT YOU WANTED FROM THIS LIFE?
* I DID....
* AND WHAT DID YOU WANT?
* TO CALL MYSELF BELOVED.
* TO FEEL MYSELF BELOVED ON THE EARTH....
*/
#include <bits/stdc++.h>
#define sz(x) (x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define ___WTHIT___ main
//#include <boost/accumulators/accumulators.hpp>
//#include <dirent.h>
//#include <stdio.h>
//#pragma comment(linker, "/STACK:16777216")
//#define M 300002
//#define pi 3.14159265358979323846
#define MINF -2000000000
//#define M  100005
#define K 28
using namespace std;
typedef long long ll;
//typedef long long ull;
const ll INF = 1.e18 + 2;
const ll mod = 1000000007;
const int MAXN = 100005;
using namespace std;
vector <string> v;
string s;
const int p = 203;
vector<ll> p_pow (MAXN);
vector <ll> h (MAXN);
int i1, j1, i2, j2;
void init() {
    p_pow[0] = 1;
        for (int i = 1; i < p_pow.size(); ++i) p_pow[i] = (p_pow[i-1] * p) % mod;
	    for (int i = 0; i < s.length(); ++i) {
	            h[i] = ( (s[i] - 'a' + 1) * p_pow[i] ) % mod;
		            if (i) {
			                h[i] += h[i-1];
					            h[i] %= mod;
						            }
							        }
								}
								ll bin_pow(ll a, ll c) {
								    if(c == 0) return 1LL;
								        if(c % 2) return bin_pow(a, c - 1) * a % mod;
									    else {
									            ll res = bin_pow(a, c / 2);
										            return res * res % mod;
											        }
												}
												ll inverse(ll a) {
												    return bin_pow(a, mod - 2);
												    }
												    int main() {
												        //freopen("substrcmp.in", "r", stdin);
													    //freopen("substrcmp.out", "w", stdout);
													        cin >> s;
														    int m; cin >> m;
														        init();
															    for(int i = 0; i < m; ++i) {
															            scanf("%d%d%d%d", &i1, &j1, &i2, &j2);
																            ll h1 = h[j1 - 1];
																	            if(i1 - 1) h1 -= h[i1 - 2];
																		            h1 += mod; h1 %= mod;
																			            h1 *= inverse(p_pow[i1 - 1] % mod) % mod; h1 %= mod;
																				            ll h2 = h[j2 - 1];
																					            if(i2 - 1) h2 -= h[i2 - 2];
																						            h2 += mod; h2 %= mod;
																							            h2 *= inverse(p_pow[i2 - 1] % mod) % mod; h2 %= mod;
																								           if(h1 == h2) printf("Yes\n");
																									          else printf("No\n");
																										      }
																										          return 0;
																											  }


