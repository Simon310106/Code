#include <bits/stdc++.h>
using namespace std;

int factor(int k, int n) {
	if (k == 1) {
		return 1;
	}
	int cnt = 0;
	for (int i = n; i <= k; i++) {
		if (k % i == 0) {
			cnt += factor(k / i, i);
		}
	}
	return cnt;
}

int main(){
	int n;
	cin >> n;
	while(n--) {
		int a;
		cin >> a;
		cout << factor(a, 2) << endl;
	}
	return 0;
}
