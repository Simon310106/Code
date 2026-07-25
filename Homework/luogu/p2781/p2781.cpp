#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

const int N = 6e6 + 5;
int s[N], tag[N];
int L[N], R[N];
int n, m, cnt = 1;

void up(int i) {
    s[i] = s[L[i]] + s[R[i]];
}

void down(int i, int l, int r) {
    if (!tag[i]) return;
    if (!L[i]) L[i] = ++cnt;
    if (!R[i]) R[i] = ++cnt;
    int mid = (l + r) >> 1;
    s[L[i]] += 1ull * (mid - l + 1) * tag[i];
    tag[L[i]] += tag[i];
    s[R[i]] += 1ull * (r - mid) * tag[i];
    tag[R[i]] += tag[i];
    tag[i] = 0;
}

void update(int i, int l, int r, int ul, int ur, int v) {
    if (ul <= l && ur >= r) {
        s[i] += 1ull * (r - l + 1) * v;
        tag[i] += v;
        return;
    }
    down(i, l, r);
    int mid = (l + r) >> 1;
    if (ul <= mid){
        if (!L[i]) L[i] = ++cnt;
        update(L[i], l, mid, ul, ur, v);
    }
    if (ur > mid){
        if (!R[i]) R[i] = ++cnt;
        update(R[i], mid + 1, r, ul, ur, v);
    }
    up(i);
}

int query(int i, int l, int r, int ql, int qr) {
    if (!i) return 0;
    if (ql <= l && qr >= r) {
        return s[i];
    }
    down(i, l, r);
    int mid = (l + r) >> 1;
    int ans = 0;
    if (ql <= mid) ans += query(L[i], l, mid, ql, qr);
    if (qr > mid)  ans += query(R[i], mid + 1, r, ql, qr);
    return ans;
}

signed main(){
    cin >> n >> m;
    while (m--) {
        int opr;
        cin >> opr;
        if (opr == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            update(1, 1, n, l, r, k);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        }
    }
    return 0;
}