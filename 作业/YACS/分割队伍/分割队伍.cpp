#include <bits/stdc++.h>
using namespace std;

int a[100005], sum[100005];

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	int ans = INT_MAX;
	for (int i = 1; i <= n; i++) {
		ans = min(ans, abs(sum[i] - (sum[n] - sum[i])));
	}
	cout << ans;
	return 0;
}

