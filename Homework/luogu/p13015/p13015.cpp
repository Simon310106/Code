#include <bits/stdc++.h>
using namespace std;

int n;
int a[1020], dp[1020];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			dp[j] = max(dp[j], dp[j - i] + a[i]);
		} 
	}
	cout << dp[n];
	return 0;
}

