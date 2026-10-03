#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

const int N = 1e5+5;
vector<PII> g[N];
int r[N], dist[N];

int main(){
	int n, q;
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> r[i];
		if (i != 1) {
			g[i].push_back({i - 1, 1});
			if (r[i] != 0) {
				g[i].push_back({r[i], 1});
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		memset(dist, 0x3f, sizeof dist);
		dist[x] = 0;
		priority_queue<PII, vector<PII>, greater<PII>> q;
		q.push({0, x});
		while (!q.empty()) {
			auto[d, u] = q.top();
			q.pop();
			if (d > dist[u]) continue;
			for (auto [v, w] : g[u]) {
				if (dist[v] > dist[u] + w) {
					dist[v] = dist[u] + w;
					q.push({dist[v], v});
				}
			}
		}
		printf("%d\n", dist[y]);
	}
	return 0;
}

