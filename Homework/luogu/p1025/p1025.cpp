#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
int a[205];

void dfs(int x, int sum) {
	if (x > k) {
		if (sum == n) {
			ans++;
		}
		return;
	}
	if (sum > n) {
		return;
	}
	for (int i = a[x - 1]; i <= n - sum; i++) {
		a[x] = i;
		dfs(x + 1, sum + a[x]);
	}
}

int main(){
	cin >> n >> k;
	a[0] = 1; 
	dfs(1, 0);
	cout << ans;
	return 0;
}

