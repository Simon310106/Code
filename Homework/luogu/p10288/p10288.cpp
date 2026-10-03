#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N], b[N];

int main(){
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b + 1, b + 1 + n);
		for (int i = 1; i <= n; i++) {
			a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
		}
		int q;
		cin >> q;
		for (int i = 1; i <= q; i++) {
			int l, r, x;
			cin >> l >> r >> x;
			int tmp[N];
			memcpy(tmp, a, sizeof a);
			sort(tmp + l, tmp + r + 1);
			x = lower_bound(b + 1, b + n + 1, x) - b;
			int ans = upper_bound(tmp + l, tmp + r + 1, x) - lower_bound(tmp + l, tmp + r + 1, x);
			cout << ans << endl;
		}
	} 
	return 0;
}

