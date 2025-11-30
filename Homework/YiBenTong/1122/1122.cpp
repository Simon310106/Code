#include <bits/stdc++.h>
using namespace std;

int a[10][10], ma = 0, mi = 0x3f3f3f3f, row, col, ans;
bool f = 1;

int main()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j]; 
		}
	}
	for (int i = 0; i < 5; i++) {
		ma = 0;
		f = 1;
		for (int j = 0; j < 5; j++) {
			if (a[i][ma] < a[i][j]) {
				ma = j;
			}
		}
		for (int j = 0; j < 5; j++) {
			if (a[j][ma] < a[i][ma]) {
				f = 0;
				break;
			}
		}
		if (f == 1) {
			cout << i + 1 << " " << ma + 1 << " " << a[i][ma];
			return 0;
		}
	}
	cout << "not found";
	
	return 0;
}
