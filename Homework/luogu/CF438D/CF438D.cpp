#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5;
int a[N], s[4 * N], ma[4 * N];
int n, m;

void pushup(int i) {
    s[i] = s[i << 1] + s[i << 1 | 1];
    ma[i] = max(ma[i << 1], ma[i << 1 | 1]);
}

void build(int i, int l, int r) {
    if (l == r) {
        s[i] = a[l];
        ma[i] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    pushup(i);
}

void mod(int i, int l, int r, int ql, int qr, int x) {
    if (ql > r || qr < l) return;
    if (ma[i] < x) return;
    if (l == r) {
        s[i] %= x;
        ma[i] %= x;
        return;
    }
    int mid = (l + r) >> 1;
    mod(i << 1, l, mid, ql, qr, x);
    mod(i << 1 | 1, mid + 1, r, ql, qr, x);
    pushup(i);
}

void add(int i, int l, int r, int x, int k) {
    if (l == r) {
        s[i] = k;
        ma[i] = k;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) {
        add(i << 1, l, mid, x, k);
    }
    else {
        add(i << 1 | 1, mid + 1, r, x, k);
    }
    pushup(i);
}

int query(int i, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) {
        return s[i];
    }
    int mid = (l + r) >> 1;
    int L = query(i << 1, l, mid, ql, qr);
    int R = query(i << 1 | 1, mid + 1, r, ql, qr);
    return L + R;
}

signed main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--) {
        int opr;
        cin >> opr;
        if (opr == 1) {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        }
        else if (opr == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            mod(1, 1, n, l, r, x);
        }
        else {
            int k, x;
            cin >> k >> x;
            add(1, 1, n, k, x);
        }
    }
    return 0;
}