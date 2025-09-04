#include <bits/stdc++.h>
using namespace std;

int n, m, a[70], vis[70], len, nt[70];

bool dfs(int cnt, int sum, int x) {
    if (cnt * len == m) return 1; 
    if (sum == len) return dfs(cnt + 1, 0, 1); 
    int id = lower_bound(a + x, a + n + 1, len - sum, greater<int>()) - a;
    for (int i = id; i <= n; i++) {
        if (vis[i] || sum + a[i] > len) continue;
        vis[i] = 1;
        if (dfs(cnt, sum + a[i], i + 1)) return 1;
        vis[i] = 0;
        if (sum == 0 || sum + a[i] == len) return 0; 
        i = nt[i];
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        m += a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    nt[n] = n;
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] == a[i + 1]) nt[i] = nt[i + 1];
        else nt[i] = i;
    }
    for (len = a[1]; len <= m / 2; len++) {
        if (m % len != 0) continue;
        if (dfs(0, 0, 1)) {
            cout << len << endl;
            return 0;
        }
    }
    cout << m << endl; 
    return 0;
}