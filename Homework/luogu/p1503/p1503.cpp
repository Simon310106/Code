#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;
int suf[4 * N], pre[4 * N];
stack<int> tmp;

void up(int i, int l, int r) {
	int mid = (l + r) >> 1;
	int left = i << 1;
	int right = i << 1 | 1;
	pre[i] = pre[left];
    suf[i] = suf[right];
	if (pre[left] == mid - l + 1) {
		pre[i] = pre[left] + pre[right];
	}
	if (suf[right] == r - mid) {
		suf[i] = suf[left] + suf[right];
	}
} 

void build(int i, int l, int r) {
	if (l == r) {
		suf[i] = pre[i] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
	up(i, l, r);
}

void update(int i, int l, int r, int k, int v) {
	if (l == r) {
		pre[i] = suf[i] = v;
		return;
	}
	int mid = (l + r) >> 1;
	if (k <= mid) update(i << 1, l, mid, k, v);
	else update(i << 1 | 1, mid + 1, r, k, v);
	up(i, l, r);
}

int query(int i, int l, int r, int k) {
	if (l == r) {
		return pre[i];
	}
	int mid = (l + r) >> 1;
	int left = i << 1;
	int right = i << 1 | 1;
	if (k <= mid) {
		if (k > mid - suf[left]) {
			return suf[left] + pre[right];
		}
		else {
			return query(left, l, mid, k);
		}
	}
	else {
		if (k <= mid + pre[right]) {
			return pre[right] + suf[left];
		}
		else {
			return query(right, mid + 1, r, k);
		}
	}
}


int main(){
	int n, m;
	cin >> n >> m;
	build(1, 1, n);
	while (m--) {
		char opr;
		cin >> opr;
		if (opr == 'D') {
			int k;
			cin >> k;
			tmp.push(k);
			update(1, 1, n, k, 0);
		}
		else if (opr == 'R') {
			update(1, 1, n, tmp.top(), 1);
			tmp.pop();
		}
		else {
			int pos;
			cin >> pos;
			cout << query(1, 1, n, pos) << endl;
		}
	}
	return 0;
}

