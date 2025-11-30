#include <bits/stdc++.h>
using namespace std;

int a[15][15], m, n;

int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j]; 
		}
	}
	for (int i = m - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			cout << a[i][j];
			if (j != 0) {
				cout << " ";
			} 
		}
		cout << endl;
	}
	return 0;
}
