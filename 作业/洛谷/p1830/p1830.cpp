#include <bits/stdc++.h>
using namespace std;

struct boom {
	int a, b, c, d;
}c[10005];

int main(){
	int n, m, x, y, u, v, cnt = 0, ans = 0;
	cin >> n >> m >> x >> y;
	for (int i = 0; i < x; i++) {
		cin >> c[i].a >> c[i].b >> c[i].c >> c[i].d;
	}
	for (int i = 0; i < y; i++) {
		cin >> u >> v;
		cnt = 0;
		for (int j = 0; j < x; j++) {
			if (u >= c[j].a && u <= c[j].c && v >= c[j].b && v <= c[j].d) {
				cnt++;
				ans = j + 1;
			}
		}
		if (cnt > 0) {
			cout << "Y " << cnt << " " << ans << endl;
		}
		else {
			cout << "N\n";
		}
	}
	return 0;
}