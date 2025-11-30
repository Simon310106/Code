#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	int ans = a, t1 = 0, t2 = 0;
	while (a != 0) {
		a--, t1++, t2++;
		if (t1 == b) {
			a++, t1 -= b;
			ans++;
		}
		if (t2 == c) {
			a++, t2 -= c;
			ans++;
		}
	}
	cout << ans;
	return 0;
}

