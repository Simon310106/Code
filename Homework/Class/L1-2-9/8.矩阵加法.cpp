#include <bits/stdc++.h>
using namespace std;

int a[150][150], m, n, b[150][150];

int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> b[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] + b[i][j];
			if (j != n - 1) {
				cout << " ";
			}
		}
		if (i != m - 1) {
			cout << endl;
		}
	}
	return 0;
}
