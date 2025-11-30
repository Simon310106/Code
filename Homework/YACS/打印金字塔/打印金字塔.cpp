#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < 2 * (n - i + 2) - 3; j++) {
			cout << " ";
		}
		for (int j = 1; j <= i; j++) {
			cout << " /\\ ";
		}
		cout << endl;
		for (int j = 1; j < 2 * (n - i + 2) - 3; j++) {
			cout << " ";
		}
		for (int j = 1; j <= i; j++) {
			cout << "/__\\";
		}
		cout << endl;
	}
	return 0;
}

