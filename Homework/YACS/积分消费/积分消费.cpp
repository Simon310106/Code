#include <bits/stdc++.h>
using namespace std;

int a[100005], ans;

int main(){
	int n, m;
	cin >> n >> m;
	int l = 1;
	for (int i = 1; i <= n; i++) {
		int p, c;
		scanf("%d%d", &p, &c);
		a[i] = p;
		if (i >= m) {
			l = max(l, i - m);
		}
		while (l <= i && c > 0) {
			if (a[l] <= c) {
				ans += a[l];
				c -= a[l];
				a[l] = 0;
				l++;
			}
			else {
				ans += c;
				a[l] -= c;
				c = 0;
			}
		}
		
	}
	cout << ans;
	
	return 0;
}

