#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m, f[205][205], a[205][205]; 

int dfs (int x, int y) {
	if (f[x][y]) {
		return f[x][y];
	}
	f[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx > 0 && ty > 0 && tx <= n && ty <= m && a[x][y] > a[tx][ty]) {
			f[x][y] = max(f[x][y], dfs(tx, ty) + 1);
		}
	} 
	return f[x][y];
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans = max(ans, dfs(i, j));
		}
	}
	cout << ans;
	return 0;
}

