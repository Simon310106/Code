#include <bits/stdc++.h>
using namespace std;

int prime(int n) {
	int a = n % 10 * 10 + n / 10;
	bool flag1 = 1, flag2 = 1;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			flag1 = 0;
			break;
		}
	}
	for (int i = 2; i < a; i++) {
		if (a % i == 0) {
			flag2 = 0;
		}
	}
	if (flag1 && flag2) {
		return n;
	}
	return 0;
}

int main(){
	for (int i = 0; i < 100; i++) {
		if (prime(i)) {
			cout << prime(i) << endl;
		}
	}
	
	return 0;
}
