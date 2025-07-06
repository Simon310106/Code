#include <bits/stdc++.h>
using namespace std;

int a[100005], ma;

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int sum = 0;
	for (int i = 1; i < n; i++) {
		sum += a[i];
	}
	cout << (a[n] >= sum ? "No" : "Yes");
	return 0;
}

