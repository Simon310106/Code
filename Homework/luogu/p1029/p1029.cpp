#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	while (a != 0 && b != 0){
		if (a > b) {
			a = a % b;
		}
		else {
			b = b % a;
		}
	}
	return a == 0 ? b : a;
}

int main(){
	int x, y, ans = 0;
	cin >> x >> y;
	for (int i = x; i <= y; i++) {
		if (x * y % i == 0) {
			int j = x * y / i;
			if (gcd(i, j) == x) {
				ans++;
			}
		}
	}
	cout << ans;
	
	return 0;
}
