#include <bits/stdc++.h>
using namespace std;

int n, w[205], dp[205], pre[205];
vector<int> g[205], k;

int main(){
	cin >> n;
	memset(pre, -1, sizeof(pre)); 
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		dp[i] = w[i];
	}
	while(1) {
		int x, y;
		cin >> x >> y;
		if (x == 0 && y == 0) {
			break;
		}
		g[x].push_back(y);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			if (dp[i] + w[g[i][j]] > dp[g[i][j]]) {
				dp[g[i][j]] = dp[i] + w[g[i][j]];
				pre[g[i][j]] = i;
			}
		} 
	}
	int end = 1;
	for (int i = 1; i <= n; i++) {
		if (dp[i] > dp[end]) {
			end = i;
		}
	}
	for (int i = end; i != -1; i = pre[i]) {
		k.push_back(i);
	}
	for (int i = k.size() - 1; i >= 0; i--) {
		cout << k[i];
		if (i != 0) cout << "-";
	}
	cout << endl << dp[end];
	return 0;
}

