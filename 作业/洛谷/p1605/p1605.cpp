#include <bits/stdc++.h>
using namespace std;

int vis[10][10];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m, t;
int sx, sy, fx, fy;
int ans;

void dfs(int x, int y) {
	if (x <= 0 || y <= 0 || x > n || y > m) {
		return;
	}
	if (x == fx && y == fy) {
		ans++;
		return; 
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (vis[nx][ny] != 1) {
			vis[nx][ny] = 1;
			dfs(nx, ny);
			vis[nx][ny] = 0;
		}
		
	}
}

int main(){
	cin >> n >> m >> t;
	cin >> sx >> sy >> fx >> fy;
	for (int i = 1; i <= t; i++) {
		int x, y;
		cin >> x >> y;
		vis[x][y] = 1;
	}
	vis[sx][sy] = 1; 
	dfs(sx, sy);
	cout << ans;
	return 0;
}

