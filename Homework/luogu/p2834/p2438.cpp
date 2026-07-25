#include <bits/stdc++.h>
using namespace std;

int a[1005], dp[10005];
const int mod = 1e9 + 7;

int main(){
	int n, w;
	cin >> n >> w; 
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[0] = 1; 
	for (int i = 1; i <= n; i++) {
		for (int j = a[i]; j <= w; j++) {
			dp[j] += dp[j - a[i]] % mod;
			dp[j] %= mod;
		}
	} 
	cout << dp[w] % mod;
	return 0;
}

