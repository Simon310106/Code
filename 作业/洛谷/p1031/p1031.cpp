#include <bits/stdc++.h>
using namespace std;

int a[105];

int main(){
	int n, sum = 0;
	cin >> n; 
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sum /= n;
	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] != sum) {
			a[i + 1] -= sum - a[i];
			ans++;
		}
	}
	cout << ans;
	
	return 0;
}

