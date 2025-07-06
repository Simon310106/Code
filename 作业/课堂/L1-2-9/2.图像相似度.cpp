#include <bits/stdc++.h>
using namespace std;

int m, n, a[100][100], b[100][100], cnt;

int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	cnt = m * n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> b[i][j]; 
		}
	}
	long double ans, sim = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == b[i][j]) {
				sim++;
			}
		}
	}
	ans = sim / cnt;
	cout << fixed << setprecision(2) << ans * 100 << "%";
	return 0;
}
