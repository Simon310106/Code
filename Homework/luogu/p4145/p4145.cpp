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

int query(int i, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 0;
    if (ql <= l && r <= qr) {
        return s[i];
    }
    int mid = (l + r) >> 1;
    int L = query(i << 1, l, mid, ql, qr);
    int R = query(i << 1 | 1, mid + 1, r, ql, qr);
    return L + R;
}

void update(int i, int l, int r, int ul, int ur) {
    if (l > ur || r < ul) return;
    if (ma[i] == 1) return;
    if (l == r){
        int tmp = sqrt(s[i]);
        s[i] = tmp;
        ma[i] = tmp;
        return;
    }
    int mid = (l + r) >> 1;
    update(i << 1, l, mid, ul, ur);
    update(i << 1 | 1, mid + 1, r, ul, ur);
    pushup(i);
}

signed main(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    cin >> m;
    while(m--) {
        int k, l, r;
        cin >> k >> l >> r;
        if (l > r) swap(l, r);
        if (k == 0) {
            update(1, 1, n, l, r);
        }
        else {
            cout << query(1, 1, n, l, r) << endl;
        }
    }
    return 0;
}