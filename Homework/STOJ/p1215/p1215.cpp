#include <bits/stdc++.h>
using namespace std;

int a[505], t[105];

int main(){
	int n, r;
	cin >> n >> r;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int mi = 0;
		for (int j = 1; j < r; j++) {
			if (t[j] < t[mi]) {
				mi = j;
			}
		}
		t[mi] += a[i];
		ans += t[mi];
	}
	cout << ans;
	
	return 0;
}

