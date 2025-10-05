#include <bits/stdc++.h>
using namespace std;

int m, n, k, f[100005], d[100005], sum, ans;

struct node{
	int s, w;
}a[100005];

bool cmp(node i, node j) {
	return i.w > j.w; 
}

int main(){
	cin >> m >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].s;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i].w;
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		if (f[a[i].s] >= k) {
			continue;
		}
		else {
			f[a[i].s] += a[i].w;
			d[a[i].s]++;
			sum++;
		}
	}
	for (int i = 1; i <= m; i++) {
		if (d[i] > sum - d[i] + 1 || f[i] < k) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << sum << endl;
	return 0;
}

