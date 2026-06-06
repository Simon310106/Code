#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e4 + 5;
int n;
int a[N], b[N], f[N];
int lmin[N], rmax[N];
int lowbit(int x) {
    return (x & (-x));
}

void add(int i, int k) {
    for ( ; i <= n; i += lowbit(i)) {
        f[i] += k;
    }
}

int query(int i) {
    int res = 0;
    for ( ; i; i -= lowbit(i)) {
        res += f[i];
    }
    return res;
}

int query(int L, int R) {
    return query(R) - query(L - 1);
}

signed main(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1 || b[i] != b[i - 1]) {
            b[++cnt] = b[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(b + 1, b + 1 + cnt, a[i]) - b;
    }
    // ×ó±ßÐ¡
    for (int i = 1; i <= n; i++) {
        lmin[i] += query(1, a[i] - 1);
        add(a[i], 1);
    }
    memset(f, 0, sizeof f);
    // ÓÒ±ß´ó
    for (int i = n; i >= 1; i--) {
        rmax[i] += query(a[i] + 1, n);
        add(a[i], 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        // cout << lmin[i] << " " << a[i] << " " << rmax[i] << endl;
        ans += lmin[i] * rmax[i];
    }
    cout << ans << endl;
    return 0;
}