#include <bits/stdc++.h>
using namespace std;

int n, a[500005], minn[500005], maxn[500005], num, mi = -0x3f3f3f3f, ans;
bool flag = 0;

int main(){
	memset(minn, 0x3f, sizeof(minn));
	memset(maxn, -0x3f, sizeof(maxn));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxn[i] = max(a[i], maxn[i - 1] + a[i]);
		minn[i] = min(a[i], minn[i - 1] + a[i]);
		num += a[i];
		mi = max(mi, a[i]);
		if (a[i] > 0) {
			flag = 1;
		}
	} 
	for (int i = 1; i <= n; i++) {
		ans = max(ans, max(maxn[i], num - minn[i]));
	}
	if (!flag) {
		cout << mi;
	}
	else cout << ans;
	
	return 0;
}

