#include <bits/stdc++.h>
using namespace std;

int k, n, m, a[10005], cnt[10005];
bool vis[10005];
vector<int> g[10005];

void dfs(int x) {
    vis[x] = true;
    cnt[x]++;
    for (int i = 0; i < g[x].size(); i++) {
        if (!vis[g[x][i]]) {
            dfs(g[x][i]);
        }
    }
}

int main(){
    cin >> k >> n >> m;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= k; i++) {
        memset(vis, 0, sizeof(vis));
        dfs(a[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == k) {
            ans++;
        }
    }
    cout << ans;

    return 0;
}