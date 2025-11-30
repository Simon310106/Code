#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	if (n % 5 == 0 || n % 5 > 3) {
		cout << "Lying";
	}
	else {
		cout << "Fishing";
	}
	return 0;
}

