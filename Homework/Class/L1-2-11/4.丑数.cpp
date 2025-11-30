#include <bits/stdc++.h>
using namespace std;

string ugly(int n) {
	if (n == 1) {
		return "False";
	}
	while (n % 2 == 0) {
		n /= 2;
	}
	while (n % 3 == 0) {
		n /= 3;
	}
	while (n % 5 == 0) {
		n /= 5;
	}
	if (n == 1) {
		return "True";
	}
	return "False";
}

int main(){
	int n;
	cin >> n;
	cout << ugly(n);
	
	return 0;
}
