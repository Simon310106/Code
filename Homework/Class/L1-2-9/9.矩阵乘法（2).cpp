#include <bits/stdc++.h>
using namespace std;

int n, m, k, a[125][125], b[125][125], c[125][125];

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> b[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			for (int x = 0; x < m; x++) {
				c[i][j] += a[i][x] * b[x][j];
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout << c[i][j];
			if (j < k - 1) {
				cout << " ";
			}	
		}
		if (i < n - 1) {
			cout << endl;
		}
	}
	
	return 0;
}
