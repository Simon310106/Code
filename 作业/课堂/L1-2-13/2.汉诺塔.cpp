#include <bits/stdc++.h>
using namespace std;

unsigned long long hanoi(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return 2 * hanoi(n - 1) + 1;
	}
}

void hanoisteps(int n, char a, char b, char c) {
	if (n == 1) {
		cout << a << "->" << c << endl;
		return;
	}
	hanoisteps(n - 1, a, c, b);
	cout << a << "->" << c << endl;
	hanoisteps(n - 1, b, a, c);
}

int main(){
	int n;
	cin >> n;
	cout << hanoi(n) << endl;
	hanoisteps(n, 'A', 'B', 'C');
	return 0;
}
