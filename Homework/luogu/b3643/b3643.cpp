#include <bits/stdc++.h>
using namespace std;

int n, m, a[10005][10005]; 
vector<int> g[10005];

int main(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		a[u][v] = 1;
		a[v][u] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 1; i <= n; i++) {
		cout << g[i].size() << " ";
		sort(g[i].begin(), g[i].end());
		for (int j = 0; j < g[i].size(); j++) {
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

