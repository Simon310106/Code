#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 5e5 + 5;
ll a[N], f[N];
int n, q;

ll lowbit(int x) {
    return (x & (-x));
}

void add(int pos, int val) {
    for ( ; pos <= n; pos += lowbit(pos)) {
        f[pos] += val;
    }
}

ll query(int pos) {
    ll res = 0;
    for ( ; pos; pos -= lowbit(pos)) {
        res += f[pos];
    }
    return res;
}

ll query(int L, int R) {
    return query(R) - query(L - 1);
}

int main(){
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        add(i, a[i]);
    }
    while (q--) {
        int t, x, y, k;
        cin >> t;
        if (t == 1) {
            cin >> x >> k;
            add(x, k);
        }
        else {
            cin >> x >> y;
            cout << query(x, y) << endl;
        }
    }
    return 0;
}