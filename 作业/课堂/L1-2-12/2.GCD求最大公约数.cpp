#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	while (a && b) {
		if (a > b) {
			a %= b;
		}
		else {
			b %= a;
		}
	}
	return a + b;
}

int main(){
	int n, a[10025];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = gcd(a[0], a[1]); 
	for (int i = 2; i < n; i++) {
		ans = gcd(ans, a[i]);
	}
	cout << ans;
	
	return 0;
}
