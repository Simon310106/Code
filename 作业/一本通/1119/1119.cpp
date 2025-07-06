#include <bits/stdc++.h>
using namespace std;

int a[10][10], b[10];

int main(){
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
		}
	}
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < 5; i++) {
		b[i] = a[n - 1][i];
	}
	for (int i = 0; i < 5; i++) {
		a[n - 1][i] = a[m - 1][i];
	}
	for (int i = 0; i < 5; i++) {
		a[m - 1][i] = b[i];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << a[i][j];
			if (j < 4) {
				cout << " ";
			}
		}
		if (i < 4) {
			cout << endl;
		}
	}
	
	return 0;
}
