#include <bits/stdc++.h>
using namespace std;

int g[105][105], f[105][105], ans; 
const int mod = 1e9;

int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			g[i][j] = mod;
		}
		g[i][i] = 0;
	} 
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = min(g[u][v], w);
		g[v][u] = min(g[v][u], w); 
	}
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			
			for(int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					f[i][j] = g[i][j];
				}
			}
			
			for (int k = l; k <= r; k++) {
				for (int i = l; i <= r; i++) {
					for (int j = l; j <= r; j++) {
						f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
					}
				}
			}
			
			for (int i = l; i <= r; i++) {
				for (int j = i; j <= r; j++) {
					ans = (ans + f[i][j]) % mod;
				}
			}
			
		}
	}
	cout << ans % mod << endl;
	return 0;
}

