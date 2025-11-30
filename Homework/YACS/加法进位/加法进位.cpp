#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	int ans = 0, x = 0;
	while (a != 0 || b != 0) {
		int s = a % 10, t = b % 10;
		if (s + t + x >= 10) {
			ans++;
			x = 1;
		}
		else {
			x = 0;
		}
		a /= 10, b /= 10;
	}
	cout << ans; 
	return 0;
}

