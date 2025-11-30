#include <bits/stdc++.h>
using namespace std;

int a[105][105];

int main(){
	int n, m;
	cin >> n >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
	int q;
	cin >> q;
	while (q--) {
		int v;
		cin >> v;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (a[v][i]) {
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

