#include <bits/stdc++.h>
using namespace std;

int dp[30][30], vis[30][30]; 

int main(){
	int x, y, m, n;
	cin >> n >> m >> x >> y;
	n += 2, m += 2, x += 2, y += 2;
	dp[2][2] = 1; 
	vis[x][y] = vis[x-2][y-1] = vis[x-2][y+1] = vis[x-1][y+2] = vis[x+1][y+2]
			  = vis[x+2][y+1] = vis[x+2][y-1] = vis[x+1][y-2] = vis[x-1][y-2] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			if (vis[i][j] || (i == 2 && j == 2)) continue;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}

