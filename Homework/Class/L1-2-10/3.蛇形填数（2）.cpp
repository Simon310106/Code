#include <bits/stdc++.h>
using namespace std;

int n, a[10][10];

int main()
{
	cin >> n;
	int x = 1, y = n;
	char d = 's';
	for (int i = 1; i <= n * n; i++) {
		a[x][y] = i;
		if (d == 's') {
			if (x + 1 <= n && a[x + 1][y] == 0)
				x++;
			else {
				d = 'w';
				y--;
			}
		}
		else if (d == 'w') {
			if (y - 1 >= 1 && a[x][y - 1] == 0)
				y--;
			else {
				d = 'n';
				x--;
			}
		}
		else if (d == 'n') {
			if (x - 1 >= 1 && a[x - 1][y] == 0)
				x--;
			else {
				d = 'e';
				y++;
			}
		}
		else if (d == 'e') {
			if (y + 1 <= n && a[x][y + 1] == 0)
				y++;
			else {
				d = 's';
				x++; 
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << a[i][j];
			if (j < n) {
				cout << " ";
			}
		}
		if (i < n) {
			cout << endl;
		}
	}
	
	return 0;
}
