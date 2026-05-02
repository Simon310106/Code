#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e3 + 10, M = 5e5 + 10, MOD = 80112002;
vector<int> g[N];
queue<int> q;
int indeg[N], outdeg[N], ans, dp[N];

signed main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        indeg[b]++;
        outdeg[a]++;
    }
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
            dp[i] = 1;
        }
    }
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int v : g[t]) {
            dp[v] = (dp[v] + dp[t]) % MOD;
            indeg[v]--;
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (outdeg[i] == 0) {
            ans = (ans + dp[i]) % MOD;
        }
    }
    cout << ans;
    return 0;
}