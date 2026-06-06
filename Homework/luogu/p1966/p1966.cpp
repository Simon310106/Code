#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10, MOD = 1e8 - 3;
int n;
int a[N], b[N], c[N], f[N], tmp[N];

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
        tmp[i] = a[i];
    }
    sort(tmp + 1, tmp + 1 + n);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1 || tmp[i] != tmp[i - 1]) {
            tmp[++cnt] = tmp[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(tmp + 1, tmp + cnt + 1, a[i]) - tmp;
    }
    memset(tmp, 0, sizeof tmp);

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        tmp[i] = b[i];
    }
    sort(tmp + 1, tmp + 1 + n);
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1 || tmp[i] != tmp[i - 1]) {
            tmp[++cnt] = tmp[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        b[i] = lower_bound(tmp + 1, tmp + cnt + 1, b[i]) - tmp;
    }
    memset(tmp, 0, sizeof tmp);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        c[b[i]] = a[i];
    }
    // cout << "1\n";
    // for (int i = 1; i <= n; i++) {
    //     cout << c[i] << " ";
    // }
    // cout << "\n";
    for (int i = 1; i <= n; i++) {
        ans += query(c[i] + 1, n);
        ans %= MOD;
        add(c[i], 1);
    }
    // cout << "2\n";
    cout << ans % MOD;
    return 0;
}