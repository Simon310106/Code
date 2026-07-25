#include <bits/stdc++.h>
using namespace std;

int check(int x) {
	while (x % 2 == 0) {
		x /= 2;
	}
	while (x % 3 == 0) {
		x /= 3;
	}
	while (x % 5 == 0) {
		x /= 5;
	}
	return (x == 1 ? 1 : 0);
}

int main(){
	for (int i = 1, cnt = 1; cnt <= 1690; i++) {
		if (check(i)) {
			cout << i << ", ";
			cnt++;
		}
	}
	return 0;
}