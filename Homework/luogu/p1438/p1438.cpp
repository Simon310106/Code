#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5;
int n, m, s[4*N], a[4*N], tag[4*N];

void up(int i) {
    s[i] = s[i << 1] + s[i << 1 | 1];
}

void down(int i, int l, int r) {
    if(!tag[i]) return;
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
    if (ul > r || ur < l) return;
    if (ul <= l && ur >= r) {
        s[i] += (r - l + 1) * v;
        tag[i] += v;
        return;
    }
    down(i, l, r);
    int mid = (l + r) >> 1;
    update(i << 1, l, mid, ul, ur, v);
    update(i << 1 | 1, mid + 1, r, ul, ur, v);
    up(i);
}

int query(int i, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return s[i];
    down(i, l, r);
    int mid = (l + r) >> 1;
    int L = query(i << 1, l, mid, ql, qr);
    int R = query(i << 1 | 1, mid + 1, r, ql, qr);
    return L + R;
}

signed main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while (m--) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int l, r, k, d;
            cin >> l >> r >> k >> d;
            update(1, 1, n, l, l, k);
            if (l + 1 <= r) update(1, 1, n, l + 1, r, d);
            if (r + 1 <= n) update(1, 1, n, r + 1, r + 1, -(k + (r - l) * d));
        }
        else {
            int p;
            cin >> p;
            cout << query(1, 1, n, 1, p) + a[p] << endl;
        }
    }
    return 0;
}