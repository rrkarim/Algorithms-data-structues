#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10, M = 26;
int ch[N][M], sz, n,k;
char s[N];
void insert(const char* s) {
	int u = 0, l = strlen(s);
	for (int i=0; i<l; u=ch[u][s[i++] - 'a'])
		if(!ch[u][s[i] - 'a'])
			ch[u][s[i] - 'a'] = ++sz;
}

int dfs(int x) {
	int flag = 1, ans = 0;
	for (int i = 0; i < M; i++)
		if(ch[x][i]) {
			flag = 0;
			ans |= dfs(ch[x][i])^3;
		}
	if(flag) ans = 1;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for (int i=0; i<n; i++) {
		cin>>s;
		insert(s);
	}

	int t=dfs(0);
	if(t==3||((t>1)&&(k&1))) cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}