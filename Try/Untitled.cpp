#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, a[300005], r[300005], ans;

void msort(int s, int t) {
	if (s == t) {
		return;
	}
	int mid = (s + t) >> 1;
	msort(mid + 1, t);
	msort(s, mid);
	int i = s, j = mid + 1, k = s;
	while (i <= mid && j <= t) {
		if (a[i] > a[j]) {
			r[k] = a[i];
			k++;
			i++;
		}
		else {
			ans += mid - i + 1;
			r[k] = a[j];
			k++;
			j++;
		}
	}
	while (i <= mid){
		r[k] = a[i];
		k++;
		i++;
	}
	while (j <= t) {
		r[k] = a[j];
		k++;
		j++;
	}
	for (int i = s; i <= t; i++) {
		a[i] = r[i];
	}
}

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	msort(1, n);
	cout << ans;
	return 0;
} 
