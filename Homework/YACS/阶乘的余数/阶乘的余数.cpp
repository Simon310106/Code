#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n, m;
	cin >> n >> m;
	long long ans = 1;
	for (long long i = 1; i <= n; i++) {
		ans *= i;
		ans %= m;
	}
	cout << ans;
	return 0;
}

