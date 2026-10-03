#include <bits/stdc++.h>
using namespace std;

struct node {
	int a, b;
	double w;
}e[250005];

int n, l, cnt, f[505];
int edgeCnt;
double res;
int x[505], y[505];

bool cmp(node a, node b) {
	return a.w < b.w;
} 
int find(int a) {
	if (f[a] != a) f[a] = find(f[a]);
	return f[a];
}
void kruskal() {
	for (int i = 1; i <= edgeCnt; i++) {
		int pa = find(e[i].a);
		int pb = find(e[i].b);
		if (pa != pb) {
			res += e[i].w;
			f[pa] = pb;
			cnt++;
		}
	}
}

int main(){
	cin >> n >> l;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		f[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int nx = x[i] - x[j], ny = y[i] - y[j];
			nx *= nx;
			ny *= ny;
			if (nx + ny <= l * l) {
				e[++edgeCnt] = {i, j, sqrt(nx + ny)};
			}
		}
	}
	sort(e + 1, e + 1 + edgeCnt, cmp); 
	kruskal(); 
	if (cnt < n - 1) {
		cout << "Impossible" << endl;
	}
	else {
		cout << fixed << setprecision(2) << res << endl;
	}
	return 0;
}

