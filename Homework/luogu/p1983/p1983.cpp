#include <bits/stdc++.h>
using namespace std;

int n, m;
int stop[1005], indeg[1005], dp[1005];
bool is[1005], vis[1005][1005];
vector<int> g[1005];
queue<int> q;

int main(){
    cin >> n >> m;
    int tot = n;
    for (int i = 1; i <= m; i++) {
        memset(is, 0, sizeof is);
        int s;
        cin >> s;
        for (int j = 1; j <= s; j++) {
            cin >> stop[j];
            is[stop[j]] = 1;
        }
        for (int j = stop[1]; j <= stop[s]; j++) {
            if (is[j]) {
                continue;
            }
            for (int k = 1; k <= s; k++) {
                if (vis[j][stop[k]]) continue;
                vis[j][stop[k]] = 1;
                indeg[stop[k]]++;
                g[j].push_back(stop[k]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int t = q.front(); q.pop();
        for (int v : g[t]) {
            dp[v] = max(dp[v], dp[t] + 1);
            indeg[v]--;
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans + 1;
    return 0;
}