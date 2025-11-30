#include <bits/stdc++.h>
using namespace std;

int a[30010];

int main(){
	int w, n;
	cin >> w >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int sum = 0, ans = 0;
	int l = 0, r = n - 1;
	while (l <= r) {
		if (a[l] + a[r] <= w && l != r) {
			l++;
			r--;
			ans++;
		}
		else {
			r--;
			ans++;
		}
	}
	cout << ans;
	return 0;
}

