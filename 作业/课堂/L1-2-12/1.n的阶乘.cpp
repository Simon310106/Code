#include <bits/stdc++.h>
using namespace std;

unsigned long long factorial(int n) {
	unsigned long long ans = 1;
	for (int i = 1; i <= n; i++) {
		ans *= i;
	}
	return ans;
} 

int main(){
	int a;
	cin >> a;
	cout << factorial(a);
	
	return 0;
}
