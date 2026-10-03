#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, f[N], res, cnt;

struct node {
	int a, b, w;
}e[N];

bool cmp(node a, node b) {
	return a.w < b.w;
}

int find(int a) {
	if (f[a] != a) return f[a] = find(f[a]);
	return f[a];
}

void kruskal() {
	for (int i = 1; i <= m; i++) {
		if (e[i].a == 0 && e[i].b == 0 && e[i].w == 0) continue;
		int pa = find(e[i].a);
		int pb = find(e[i].b);
		if (pa != pb) {
			res += e[i].w;
			cnt++;
			f[pa] = pb;
		}
	}
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		cin >> e[i].a >> e[i].b >> e[i].w;
	}
	sort(e + 1, e + 1 + m, cmp);
	node tmp;
	for (int i = 1; i <= m; i++) {
		res = 0;
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			f[i] = i;
		}
		
		tmp = e[i];
		e[i] = {0, 0, 0};
		kruskal();
		if (cnt < n - 1) {
			cout << -1 << endl;
		}
		else {
			cout << res << endl;
		}
		e[i] = tmp;
	}
	return 0;
}

