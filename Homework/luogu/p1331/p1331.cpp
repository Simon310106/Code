#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, boat, temp;
char a[1050][1050];

void dfs(int x, int y) {
	boat++;
	a[x][y] = '.';
	if (x - 1 >= 0 && a[x - 1][y] != '.') {
		dfs(x - 1, y);
	}
	if (y - 1 >= 0 && a[x][y - 1] != '.') {
		dfs(x, y - 1);
	}
	if (x + 1 < n && a[x + 1][y] != '.') {
		dfs(x + 1, y);
	}
	if (y + 1 < m && a[x][y + 1] != '.') {
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
			if (a[i][j] == '#') {
				boat = 0;
				int r = 0, c = 0;
				for (int k = i; k < n; k++) {
					if (a[k][j] == '#') {
						r++;
					}
					else {
						break;
					}
				}
				for (int k = j; k < m; k++) {
					if (a[i][k] == '#') {
						c++;
					}
					else {
						break;
					}
				}
				dfs(i, j);
				temp = r * c;
				if (temp != boat) {
					cout << "Bad placement.";
					return 0;
				}
                cnt++;
			}
		}
	}
	cout << "There are " << cnt << " ships.";
	return 0;
}
