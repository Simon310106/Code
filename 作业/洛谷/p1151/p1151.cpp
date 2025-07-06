#include <bits/stdc++.h>
using namespace std;

bool number(int t, int k) {
	int a, b, c;
	a = t / 100;
	b = (t / 10) % 1000;
	c = t % 1000;
	if (a % k == 0 && b % k == 0 && c % k == 0) {
		return 1;
	}
	return 0;
}

int main(){
	int k, ans = 0;
	cin >> k;
	for (int i = 10000; i <= 30000; i++) {
		if (number(i, k)) {
			cout << i << endl;
			ans++;
		}
	}
	if (ans == 0) {
		cout << "No";
	}
	
	return 0;
}
