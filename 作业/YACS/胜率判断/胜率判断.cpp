#include <bits/stdc++.h>
using namespace std;

int main(){
	double a, b, x, y;
	cin >> a >> b >> x >> y;
	if (a / b > x / y) {
		cout << ">";
	}
	else if (a / b == x / y) {
		cout << "=";
	}
	else {
		cout << "<";
	}
	return 0;
}

