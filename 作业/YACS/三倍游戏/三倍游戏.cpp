#include <bits/stdc++.h>
using namespace std;

int a[5]; 

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		a[temp % 3]++;
	}
	int ans = a[0] / 2 + min(a[1], a[2]);
	cout << ans;
	return 0;
}

