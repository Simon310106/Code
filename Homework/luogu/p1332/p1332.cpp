#include <bits/stdc++.h>
using namespace std;

int a[100050], b[100050];

int main(){
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	for (int i = 0; i < x; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i < y; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		int m = 0x3f3f3f3f;
		for (int j = 0; j < x; j++) {
			m = min(abs(a[j] - t1) + abs(b[j]-t2), m);
		}
		cout << m << endl;
	}
	
	return 0;
}
