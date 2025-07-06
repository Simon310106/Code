#include <bits/stdc++.h>
using namespace std;

int a[1025][1025], n;

int main(){
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == 0) {
				a[i][j] += a[i - 1][j];
			}
			else if (j == i) {
				a[i][j] += a[i - 1][j - 1];
			}
			else {
				a[i][j] += max(a[i - 1][j], a[i - 1][j - 1]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(a[n - 1][i], ans);
	}
	cout << ans;
	
	return 0;
}
