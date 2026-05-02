#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;
int a[N], f1[N], f2[N];
int n, q;

int lowbit(int x) {
    return (x & (-x));
}

void add(int f[], int i, int k) {
    for (; i <= n; i += lowbit(i)) {
        f[i] += k;
    }
}

int query(int f[], int k) {
    int res = 0;
    for (; k; k -= lowbit(k)) {
        res += f[k];
    }
    return res;
}

int query(int x) {
    return query(f1, x) * (x + 1) - query(f2, x);
}

signed main(){
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int t = a[i] - a[i - 1];
        add(f1, i, t);
        add(f2, i, i * t);
    }
    while (q--) {
        int t, x, y, k;
        cin >> t;
        if (t == 1) {
            cin >> x >> y >> k;
            add(f1, x, k);
            add(f1, y + 1, -k);
            add(f2, x, x * k);
            add(f2, y + 1, -(y + 1) * k);
        }
        else {
            cin >> x >> y;
            cout << query(y) - query(x - 1) << endl;
        }
    }
    return 0;
}