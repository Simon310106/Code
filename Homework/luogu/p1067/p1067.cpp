#include <bits/stdc++.h>
using namespace std;

int n, a[200];
bool fst = 1, flag = 0;

int main(){
	cin >> n;
	for (int i = n; i >= 0; i--) {
		cin >> a[i];
		if (a[i] != 0) {
			flag = 1;
		}
	}
	if (flag == 0) {
		cout << 0;
		return 0;
	}
	for (int i = n; i >= 2; i--) {
		if (a[i] > 0) {
			if (fst) {
				fst = 0;
			}
			
			else {
				cout << "+";
			}
			if (a[i] != 1) {
				cout << a[i];
			}
			cout << "x^" << i;
		}
		else if (a[i] < 0) {
			fst = 0;
			if (a[i] == -1) {
				cout << "-";
			}
			else {
				cout << a[i];
			}
			cout << "x^" << i;
		}
	}
	if (a[1] > 0) {
		if (fst) {
			fst = 0;
		}
		else {
			cout << "+";
		}
		if (a[1] != 1) {
			cout << a[1];
		}
		cout << "x";
	}
	else if (a[1] < 0) {
		fst = 0;
		if (a[1] == -1) {
			cout << "-";
		}
		else {
			cout << a[1];
		}
		cout << "x";
	}
	if (a[0] > 0) {
		if (fst) {
			fst = 0;
		}
		else {
			cout << "+";
		}
		cout << a[0];
	} 
	else if (a[0] < 0) {
		cout << a[0];
	}
	
	return 0;
}

