#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10;
int a[N], s[4 * N], t, cnt;

void pushup(int i) {
    s[i] = max(s[i << 1], s[i << 1 | 1]);
}

void update(int i, int l, int r, int x, int k) {
    if (l == r) {
        s[i] += k;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) {
        update(i << 1, l, mid, x, k);
    }
    else {
        update(i << 1 | 1, mid + 1, r, x, k);
    }
    pushup(i);
}

int query(int i, int l, int r, int ql, int qr) {
    if (qr < l || ql > r) return 0;
    if (ql <= l && r <= qr) return s[i];
    int mid = (l + r) >> 1;
    int L = query(i << 1, l, mid, ql, qr);
    int R = query(i << 1 | 1, mid + 1, r, ql, qr);
    return max(L, R);
}

signed main(){
    int m, d;
    cin >> m >> d;
    for (int i = 1; i <= m; i++) {
        char opr;
        cin >> opr;
        if (opr == 'Q') {
            int L;
            cin >> L;
            t = query(1, 1, m, cnt - L + 1, cnt);
            cout << t << endl;
        }
        else {
            int n;
            cin >> n;
            cnt++;
            update(1, 1, m, cnt, (n + t) % d);
        }
    }
    return 0;
}
// 96 93