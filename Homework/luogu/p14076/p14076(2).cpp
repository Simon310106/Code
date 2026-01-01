#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, ma, ans, sum; 

struct node {
	ll to, c;
};

vector<node> g[100005];

void dfs(int u, int f, ll s) {
	ma = max(ma, s);
	for (int i = 0; i < g[u].size(); i++) {
		node v = g[u][i];
		if (v.to != f) {
			sum += v.c;
			dfs(v.to, u, s + v.c);
		}
	}
}

int main(){
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v, l;
		cin >> u >> v >> l;
		g[u].push_back({v, l});
		g[v].push_back({u, l});
		ans += l;
	}
	dfs(1, 0, 0);
	cout << 2 * ans - ma;
	return 0;
}

