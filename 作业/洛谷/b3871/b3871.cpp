#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			long long cnt = 0;
			while (n % i == 0) {
				n /= i;
				cnt++;
			}
			if (cnt == 1) {
				cout << i;
			}
			else {
				cout << i << "^" << cnt;
			}
			if (n > 1) {
				cout << " * ";
			}
		}
	}
	if (n > 1) {
		cout << n;
	}
	return 0;
}

