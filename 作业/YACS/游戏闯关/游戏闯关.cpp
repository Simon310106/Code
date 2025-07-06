#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int now = 0, mi = INT_MAX;
	for (int i = 1; i <= n ; i++) {
		now += a[i];
		mi = min(mi, now);
	}
	
	int ans = (mi < 0 ? -mi : 0);
	
	cout << ans + 1;
	
	return 0;
}

