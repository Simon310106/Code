#include <bits/stdc++.h>
using namespace std;

int love(int a, int b) {
	int ansa = 0;
	for (int i = 1; i < a; i++) {
		if (a % i == 0) {
			ansa += i;
		}
	}
	int ansb = 0;
	for (int i = 1; i < b; i++) {
		if (b % i == 0) {
			ansb += i;
		}
	}
	if (ansa == b && ansb == a) {
		cout << a << " " << b;
		return 1;
	}
	return 0;
}

int main(){
	for (int i = 2; i < pow(2, 31) - 1; i++) {
		for (int j = 2; j < i; j++) {
			int a = love(j, i);
			if (a) {
				return 0;
			} 
		}
	}
	
	return 0;
}
