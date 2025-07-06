#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int n;
	cin >> n;
	int sum = 1;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			sum += i;
			if (n / i != i) {
				sum += n / i;
			}
		}
	}
	if (sum > n) {
		cout << "Abundant";
	}
	else if (sum < n) {
		cout << "Deficient";
	}
	else if (sum == n) {
		cout << "Perfect";
	}
	 
	return 0;
}

