#include <bits/stdc++.h>
using namespace std;

int n, m, s, e; 
int ans;
bool vis[1005];
vector<int> g[1005];

void dfs(int x) {
	if (x == e) {
		ans++;
		return;
	}
	for (int i = 0; i < g[x].size(); i++) {
		if (vis[g[x][i]] == 0) {
			vis[g[x][i]] = 1;
			dfs(g[x][i]);
			vis[g[x][i]] = 0;
		}
	}
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cin >> s >> e;
	vis[s] = 1;
	dfs(s);
	cout << ans;
	return 0;
}

