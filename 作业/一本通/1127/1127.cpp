#include <bits/stdc++.h>
using namespace std;

int a[150][150], n, m, b[150][150];

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			b[j][n - i - 1] = a[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << b[i][j];
			if (j < n - 1) {
				cout << " ";
			}
		}
		if (i < m- 1) {
			cout << endl;
		}
	}
	
	return 0;
}
