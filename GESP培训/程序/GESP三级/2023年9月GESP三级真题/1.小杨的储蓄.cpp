#include <bits/stdc++.h>
using namespace std;

int a[1050];

int main(){
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= d; i++) {
		int t;
		cin >> t;
		a[t] += i;
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	
	return 0;
}
