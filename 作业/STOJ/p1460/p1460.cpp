#include <bits/stdc++.h>
using namespace std;

int a[10005], t[105]; 

int minarr(int n) {
	int ans = INT_MAX, id = 0;
	for (int i = 0; i < n; i++) {
		if (ans > t[i]) {
			ans = t[i];
			id = i;
		}
	}
	return id;
}

int maxarr(int n) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (ans < t[i]) {
			ans = t[i];
		}
	}
	return ans;
}

int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		t[minarr(m)] += a[i];
	}
	cout << maxarr(m);
	return 0;
}

