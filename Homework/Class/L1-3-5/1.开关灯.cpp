#include <bits/stdc++.h>
using namespace std;

bool a[5050];

int main(){
	int n, m;
	cin >> n >> m;
	memset(a, 1, sizeof(a));
	for (int i = 1; i <= m; i++) {
		if (i == 1) {
			memset(a, 0, sizeof(a));
		}
		else {
			for (int j = i; j <= n; j += i) {
				if (a[j]) {
					a[j] = 0;
				}
				else if (!a[j]) {
					a[j] = 1;
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!a[i]) {
			cnt++;
			if (cnt == 1) {
				cout << i;
			}
			else {
				cout << "," << i;
			}
		}
	}
	
	return 0;
}