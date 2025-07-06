#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[100005], r[100005];

signed main(){
	int n, r1;
	scanf("%lld%lld", &n, &r1);
	r[0] = r1;
	for (int i = 1; i < n; i++) {
		r[i] = (r[i - 1] * 6807 + 2831) % 20170;
	}
	for (int i = 0; i < n; i++) {
		a[i] = (r[i] % 100) + 1;
	}
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		a[i] = a[i] + a[i - 1];
	}
	for (int i = 0; i < n; i++) {
		ans += a[i];
	}
	printf("%lld", ans);
	return 0;
}

