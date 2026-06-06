#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int a[N], s[4 * N];

void pushup(int i) {
    s[i] = gcd(s[i << 1], s[i << 1 | 1]);
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
    if (qr < l || ql > r) return 0;
    if (ql <= l && r <= qr) return s[i];
    int mid = (l + r) >> 1;
    int L = query(i << 1, l, mid, ql, qr);
    int R = query(i << 1 | 1, mid + 1, r, ql, qr);
    return gcd(L, R);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(), cout.tie();
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while(m--) {
        int l, r;
        cin >> l >> r;
        cout << query(1, 1, n, l, r) << endl;
    }
    return 0;
}