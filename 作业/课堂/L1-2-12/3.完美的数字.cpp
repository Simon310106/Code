#include <bits/stdc++.h>
using namespace std;

bool perfect(int n) {
	int sum = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			sum += i;
		}
	}
	return (sum == n ? 1 : 0);
}

int main(){
	for (int i = 2; i < 10000; i++) {
		if (perfect(i)) {
			cout << i << " ";
		}
	}
	
	return 0;
}
