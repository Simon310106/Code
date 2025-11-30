#include <bits/stdc++.h>
using namespace std;

bool prime(int n) {
	int u = n / 10 + n % 10 * 10;
	bool flag = 1;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			flag = 0;
		}
	}
	if (flag) {
		for (int i = 2; i < u; i++) {
			if (u % i == 0) {
				flag = 0;
			}
		}
	}
	return flag;
}

int main(){
	for (int i = 2; i < 100; i++) {
		if (prime(i)) {
			cout << i << " ";
		}
	}
	
	return 0;
}
