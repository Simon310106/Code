#include <bits/stdc++.h>
using namespace std;

int main(){
	int m, n, s = 0, r = 0;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int x = i + 1; x <= n; x++) {
				for (int y = j + 1; y <= m; y++) {
					if (x - i == y - j) {
						s++;
					}
					else {
						r++;
					}
				}
			}
		}
	}
	cout << s << " " << r;
	
	return 0;
}
