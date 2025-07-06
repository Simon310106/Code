#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[a[i]] == i) {
			ans++;
		}
	}
	cout << ans / 2;
	return 0;
}

