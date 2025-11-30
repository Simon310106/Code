#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
long long a[N];

int main() {
	long long n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] + a[i - 1] > x) {
			ans += a[i] + a[i - 1] - x;
			a[i] -= a[i] + a[i - 1] - x;
		}
	}
	cout << ans;
	
	return 0;
}

