#include <bits/stdc++.h>
using namespace std;

int n, x[15], y[15], ans = 0x3f3f3f3f;

void dfs(int id, int s, int b) {
	if (id > n) {
		if (s == 1 && b == 0) {
			return; 
		}
		ans = min(abs(s - b), ans);
		return;
	}
	dfs(id + 1, s * x[id], b + y[id]);
	dfs(id + 1, s, b);
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
	dfs(1, 1, 0);
	cout << ans;
	return 0;
}

