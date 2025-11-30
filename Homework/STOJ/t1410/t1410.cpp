#include <bits/stdc++.h>
using namespace std;

int prime(int n) {
	if (n % 2 == 0) {
		return 0;
	}
	for (int i = 3; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main(){
	
	return 0;
}

