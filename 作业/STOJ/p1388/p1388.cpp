#include <bits/stdc++.h>
using namespace std;

int a[105];

int main(){
	int n;
	cin >> n;
	
	int ma = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ma = max(ma, a[i]);
	}
	
	int m;
	cin >> m;
	
	for (int i = ma; i >= 1; i--) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			cnt += a[j] / i;
			if (cnt >= m) {
				cout << i;
				return 0;
			}
		}
		if (cnt >= m) {
			cout << i;
			return 0;
		}
	}
	cout << "Failed" << endl;
	return 0;
}

