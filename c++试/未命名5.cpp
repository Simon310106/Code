#include <bits/stdc++.h>
using namespace std;

int a[30][30][30];

int main(){
	int w, x, h;
	cin >> w >> x >> h;
	int sum = w * x * h, ans = 0;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int x1, y1, z1, x2, y2, z2;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		for (int k = x1; k <= x2; k++) {
			for (int b = y1; b <= y2; b++) {
				for (int c = z1; c <= z2; c++) {
					a[k][b][c] = 1;
				}
			}
		}
	}
	for (int k = 1; k <= w; k++) {
		for (int b = 1; b <= x; b++) {
			for (int c = 1; c <= h; c++) {
				if (a[k][b][c] == 1) {
					ans++;
				}
			}
		}
	}
	cout << sum - ans;
	
	
	return 0;
}