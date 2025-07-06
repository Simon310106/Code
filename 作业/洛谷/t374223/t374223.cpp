#include <bits/stdc++.h>
using namespace std;

int a[200][200];
int po[10500][2];
int u, v;

int main(){
	int m, n, y, x;
	cin >> m >> n >> y >> x;
	for (int i = 0; i < y; i++) {
		cin >> po[i][0] >> po[i][1];
	}
	for (int i = 0; i < x; i++) {
		cin >> u >> v;
		a[u][v]++;
		if (u - 1 >= 0) {
			a[u - 1][v]++;
		}
		if (v - 1 >= 0) {
			a[u][v - 1]++;
		}
		a[u][v + 1]++;
		a[u + 1][v]++;
	}
	for (int i = 0; i < y; i++) {
		if (a[po[i][0]][po[i][1]] > 0) {
			cout << "Y " << a[po[i][0]][po[i][1]] << endl;
		}
		else {
			cout << "N" << endl;
		}
	}
	return 0;
}

