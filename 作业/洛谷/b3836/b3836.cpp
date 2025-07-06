#include <bits/stdc++.h>
using namespace std;

int main(){
	int x, y, z, n, m, ans = 0;
	cin >> x >>  y >> z >> n >> m;
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= m - i; j += z) {
			if (i * x + j / z + (m - i - j) * y == n) {
				ans++;
			}
		}
	}
	cout << ans;
	
	
	return 0;
}
