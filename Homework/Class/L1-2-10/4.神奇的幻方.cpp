#include <bits/stdc++.h>
using namespace std;

int n, a[2000][2000];

int main(){
	cin >> n;
	
	a[0][n / 2] = 1;
	for (int k = 2; k <= n * n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j != n - 1 && a[0][j] == k - 1) {
					a[n - 1][j + 1] = k;
					break;
				}
				else if (i != 0 && a[i][n - 1] == k - 1) {
					a[i - 1][0] = k;
					break;
				}
				else if (a[0][n - 1] == k - 1) {
					a[1][n - 1] = k;
					break;
				}
				else if ((i != 0 && j != n - 1) && a[i][j] == k - 1) {
					if (a[i - 1][j + 1] == 0) {
						a[i - 1][j + 1] = k;
						break;
					}
					else {
						a[i + 1][j] = k;
						break;
					}
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j];
			if (j < n - 1) {
				cout << " ";
			}
		}
		if (i < n - 1) {
				cout << endl;
			}
	}
	
	return 0;
}
