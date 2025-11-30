#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int ans = 0;
	while (n != 0) {
		int t = n % 10;
		if (t == 4 || t == 6 || t == 9 || t == 0) {
			ans += 1;
		}
		if (t == 8) {
			ans += 2;
		}
		n /= 10;
	}
	cout << ans;
	return 0;
}

