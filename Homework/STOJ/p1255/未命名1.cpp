#include <bits/stdc++.h>
using namespace std;

int n, a[205];
int g[205][205], dp[205], path[205], ans, ed;

void print(int x) {
	if (path[x] == x) {
		cout << x;
	}
	print(path[x]);
	cout << "-" << x;
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = a[i];
		path[i] = i; 
	}
	while (1) {
		int x, y;
		cin >> x >> y;
		if (x == 0 && y == 0) {
			break;
		}
		g[x][y] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (g[j][i] && dp[j] + a[i] > dp[i]) {
				dp[i] = dp[j] + a[i];
				path[i] = j;
			}
			if (ans < dp[i]) {
				ans += dp[i];
				ed = i;
			}
		}
	}
	print(ed);
	cout << endl << ans << endl;
	return 0;
}

