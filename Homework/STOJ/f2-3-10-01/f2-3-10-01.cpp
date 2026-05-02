#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 200005;
int n;
int a[N], f[N];
int l1[N], l2[N], r1[N], r2[N];
int ans1, ans2;

int lowbit(int x) {
    return (x & -x);
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
    }
    // ×ó±ßÐ¡
    for (int i = 1; i <= n; i++) {
        l1[i] += query(1, a[i] - 1);
        add(a[i], 1);
    }
    memset(f, 0, sizeof f);
    // ×ó±ß´ó
    for (int i = 1; i <= n; i++) {
        l2[i] += query(a[i] + 1, n);
        add(a[i], 1);
    }
    memset(f, 0, sizeof f);
    // ÓÒ±ßÐ¡
    for (int i = n; i >= 1; i--) {
        r1[i] = query(1, a[i] - 1);
        add(a[i], 1);
    }
    memset(f, 0, sizeof f);
    // ÓÒ±ß´ó
    for (int i = n; i >= 1; i--) {
        r2[i] = query(a[i] + 1, n);
        add(a[i], 1);
    }
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; i++) {
        ans1 += l2[i] * r2[i];
        ans2 += l1[i] * r1[i];
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}