#include <bits/stdc++.h>
using namespace std;

int n, A, B, C, x[100005], dp[100005];

int main() {
	cin >> n >> A >> B >> C;
	for (int i = 1; i <= n; i++) {
		int tmp = ((long long)A * i * i + B * i + C) % 20000;
		x[i] = tmp - 10000;
	}
	dp[1] = x[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = min(dp[i - 1], dp[i - 2]) + x[i];
	}
	cout << min(dp[n], dp[n - 1]); 
	return 0;
}

