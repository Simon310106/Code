#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int f1[N], f2[N], n, m, q, l, r;

int lowbit(int x) {
    return (x & (-x));
}

void add(int pos, int val, int f[]) {
    for ( ; pos <= n; pos += lowbit(pos)) {
        f[pos] += val;
    }
}

int query(int pos, int f[]) {
    int res = 0;
    for ( ; pos; pos -= lowbit(pos)) {
        res += f[pos];
    }
    return res;
}

int query(int L, int R) {
    return query(R, f1) - query(L - 1, f2);
}

int main(){
    cin >> n >> m;
    while (m--) {
        cin >> q >> l >> r;
        if (q == 1) {
            add(l, 1, f1);
            add(r, 1, f2);
        }
        else {
            cout << query(l, r) << endl;
        }
    }
    return 0;
}