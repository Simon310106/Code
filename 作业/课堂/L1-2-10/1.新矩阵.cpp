#include <bits/stdc++.h>
using namespace std;

int n, m, a[50][50], cnt;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j || i + j == n - 1)
				a[i][j] += m;
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j];
			if (j != n - 1) {
				cout << " ";
			}
		}
		if (i < n - 1) {
			cout << endl;
		}
	}
	
	return 0;
}
