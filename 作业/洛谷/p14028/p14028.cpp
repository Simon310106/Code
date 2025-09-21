#include <bits/stdc++.h>
#define int long long 
using namespace std;

int T, a[200005], sum[200005];

signed main(){
	cin >> T;
	while (T--) {
		memset(sum, 0, sizeof(sum));
		int m, n;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		while (m--) {
			int l, r;
			cin >> l >> r;
			sum[l]++;
			sum[r + 1]--;
		}
		int mi = 1e9, ma = 0;
		for (int i = 1; i <= n; i++) {
			sum[i] += sum[i - 1];
			ma = max(ma, a[i] - sum[i]);
			mi = min(mi, a[i] + sum[i]);
		}
		cout << max(0ll, ma - mi) << endl;
	}
	 
	return 0;
}

