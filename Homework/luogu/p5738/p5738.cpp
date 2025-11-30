#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	int mi = 0x3f3f3f3f, ma = 0;
	double sum = 0, ans = -1;
	for (int i = 0; i < n; i++) {
		mi = 0x3f3f3f3f;
		ma = 0;
		sum = 0;
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			sum += a;
			mi = min(mi, a);
			ma = max(ma, a);
		}
		sum -= mi + ma;
		sum /= m - 2.0;
		ans = max(ans, sum);
	}
	cout << fixed << setprecision(2) << ans;
//	system("pause");
	return 0;
}
