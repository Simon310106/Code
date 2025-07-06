#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 2 != 0) {
			ans += m;
		}
		else {
			ans += m / 2;
		}
	} 
	cout << ans;
	return 0;
}

