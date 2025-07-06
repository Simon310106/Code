#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	while (a <= b) {
		if (a % 7 == 0 || a % 10 == 7) {
			cout << "pass" << endl;
		}
		else {
			cout << a << endl;
		}
		a++;
	}
	return 0;
}

