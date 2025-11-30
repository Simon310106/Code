#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
char a[200][200];

void dfs(int x, int y) {
	a[x][y] = '0';
	if (x - 1 >= 0 && a[x - 1][y] != '0') {
		dfs(x - 1, y);
	}
	if (y - 1 >= 0 && a[x][y - 1] != '0') {
		dfs(x, y - 1);
	}
	if (x + 1 < n && a[x + 1][y] != '0') {
		dfs(x + 1, y);
	}
	if (y + 1 < m && a[x][y + 1] != '0') {
		dfs(x, y + 1);
	}
	return;
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != '0') {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
