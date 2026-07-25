#include <bits/stdc++.h>
using namespace std;

int n, l, r;
int dp[200005], a[200005];

int main(){
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[max(0, i - l)] + a[i], dp[max(0, i - r)] + a[i]);
	}
	cout << dp[n];
	return 0;
}

