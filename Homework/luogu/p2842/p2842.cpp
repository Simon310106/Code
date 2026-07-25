#include <bits/stdc++.h>
using namespace std;

int a[1005], dp[10005];

int main(){
	int n, w;
	cin >> n >> w; 
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0; 
	for (int i = 1; i <= n; i++) {
		for (int j = a[i]; j <= w; j++) {
			dp[j] = min(dp[j], dp[j - a[i]] + 1);
		}
	}
	cout << dp[w] << endl;
	return 0;
}

