#include <bits/stdc++.h>
using namespace std;

int a[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
	int y, m, d;
	scanf("%d-%d-%d", &y, &m, &d);
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
		a[2] = 29;
	}
	int ans = 0;
	for (int i = 1; i < m; i++) {
		ans += a[i];
	}
	ans += d;
	cout << ans;
	return 0;
}

