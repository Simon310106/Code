#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long qpow(long long a, long long b) {
	long long ans = 1;
	while (b) {
		if (b & 1) {
			ans = ans * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	return ans;
}

long long C(long long n, long long m) {
	long long ans = 1;
	if (m > n) return 0;
	for (long long i = 0; i < m; i++) {
		ans = ans * (n - i) % MOD;
		ans = ans * qpow(i + 1, MOD - 2) % MOD;
	}
	return ans; 
}

int main(){
	int m, n;
	cin >> m >> n;
	cout << C(n - 1, m - 1);
	return 0;
}

