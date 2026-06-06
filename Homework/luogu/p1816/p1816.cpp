#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N], s[N * 4];
vector<int> ans;

void pushup(int i) {
	s[i] = min(s[i << 1], s[i << 1 | 1]);
}

void build(int i, int l, int r) {
	if (l == r) {
		s[i] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
	pushup(i);
}

int query(int i, int l, int r, int ql, int qr) {
	if (qr < l || ql > r) return INT_MAX;
	if (ql <= l && r <= qr) return s[i];
	int mid = (l + r) >> 1;
	int L = query(i << 1, l, mid, ql, qr);
	int R = query(i << 1 | 1, mid + 1, r, ql, qr);
	return min(L, R);
}

int main(){
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	build(1, 1, m);
	while (n--) {
		int l, r;
		cin >> l >> r;
		ans.push_back(query(1, 1, m, l, r));
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}

