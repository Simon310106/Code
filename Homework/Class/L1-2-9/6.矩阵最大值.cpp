#include <bits/stdc++.h>
using namespace std;

int m, n, a[50][50], ma;

int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			ma = max(ma, a[i][j]);
		}
	}
	cout << ma;
	return 0;
}
