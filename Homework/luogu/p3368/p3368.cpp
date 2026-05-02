#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;
int a[N], f[N];
int n, q;

int lowbit(int x) {
    return (x & (-x));
}

void add(int i, int k) {
    for (; i <= n; i += lowbit(i)) {
        f[i] += k;
    }
}

int query(int k) {
    int res = 0;
    for (; k; k -= lowbit(k)) {
        res += f[k];
    }
    return res;
}

signed main(){
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while (q--) {
        int t, x, y, k;
        cin >> t;
        if (t == 1) {
            cin >> x >> y >> k;
            add(x, k);
            add(y + 1, -k);
        }
        else {
            cin >> x;
            cout << query(x) + a[x] << endl;
        }
    }
    return 0;
}