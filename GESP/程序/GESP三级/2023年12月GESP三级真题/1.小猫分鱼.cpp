#include <bits/stdc++.h>
using namespace std;

int n, i, x, y;

int main(){
	cin >> n >> i;
	while (++x) {
		int t = x;
		bool flag = 1;
		for (int j = 1; j < n; j++) {
			y = t * n + i;
			if (y % (n - 1) != 0) {
				flag = 0;
				break;
			}
			else {
				t = y / (n - 1);
			}
		}
		if (flag) {
			cout << t * n + i;
			break;
		}
		
	}
	
	return 0;
}
