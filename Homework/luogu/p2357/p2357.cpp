#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int a[N], s[4 * N], tag[4 * N];

void pushup(int i){
	s[i] = s[i << 1] + s[i << 1 | 1];
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

void pushdown(int i, int l, int r) {
	int mid = (l + r) >> 1;
	int left = i << 1;
	int right = i << 1 | 1;
	s[left] += (mid - l + 1) * tag[i];
	tag[left] += tag[i];
	s[right] += (r - mid) * tag[i];
	tag[right] += tag[i];
	tag[i] = 0;
}

void update(int i, int l, int r, int ul, int ur, int v) {
	if (l > ur || r < ul) return;
	if (ul <= l && r <= ur) {
		s[i] += (r - l + 1) * v;
		tag[i] += v;
		return;
	}
	pushdown(i, l, r);
	int mid = (l + r) >> 1;
	update(i << 1, l, mid, ul, ur, v);
	update(i << 1 | 1, mid + 1, r, ul, ur, v);
	pushup(i);
}

int query(int i, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) return 0;
	if (ql <= l && r <= qr) {
		return s[i];
	}
	pushdown(i, l, r);
	int mid = (l + r) >> 1;
	int L = query(i << 1, l, mid, ql, qr);
	int R = query(i << 1 | 1, mid + 1, r, ql, qr);
	return L + R;
}

signed main(){
	int n, f;
	cin >> n >> f;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, 1, n);
	while(f--) {
		int opr;
		cin >> opr;
		if (opr == 1) {
			int l, r, k;
			cin >> l >> r >> k;
			update(1, 1, n, l, r, k);
		}
		else if(opr == 2) {
			int k;
			cin >> k;
			update(1, 1, n, 1, 1, k);
		}
		else if (opr == 3) {
			int k;
			cin >> k;
			update(1, 1, n, 1, 1, -k);
		}
		else if (opr == 4) {
			int l, r;
			cin >> l >> r;
			cout << query(1, 1, n, l, r) << endl;
		}
		else {
			cout << query(1, 1, n, 1, 1) << endl;
		}
	}
	return 0;
}

