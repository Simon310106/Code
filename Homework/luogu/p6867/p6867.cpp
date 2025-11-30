#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k, a[505][505], g[505][505];

signed main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    int u = 1, v = 2, cnt = 1;
    while (cnt < k && !g[u][v]) {
        g[u][v] = cnt;
        cnt++;
        int tmp = u;
        u = v;
        v = a[v][tmp];
    }
    if (cnt == k) {
        cout << u << endl;
        return 0;
    }
    cnt = cnt - g[u][v];
    k -= g[u][v] - 1;
    k %= cnt;
    if (k == 0) {
        k = cnt;
    }
    cnt = 1;
    while (cnt < k) {
        cnt++;
        int tmp = u;
        u = v;
        v = a[v][tmp];
    }
    cout << u << endl;
    return 0;
}