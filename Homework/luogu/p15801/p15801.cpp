#include <bits/stdc++.h>
using namespace std;

int ans;
int g[100005][3];
int h[100005], tree[100005], vis[100005];

void dfs(int u) {
    if (g[u][1] == 0 && g[u][2] == 0) {
        h[u] = 1;
        tree[u] = 1;
        vis[u] = 1;
        ans++;
        return;
    }
    tree[u] = 1;
    if (g[u][1]) {
        dfs(g[u][1]);
        h[u] = h[g[u][1]] + 1;
        tree[u] += tree[g[u][1]];
    }
    if (g[u][2]) {
        dfs(g[u][2]);
        h[u] = max(h[u], h[g[u][2]] + 1);
        tree[u] += tree[g[u][2]];
    }
    if (vis[g[u][1]] && !g[u][2]) {
        vis[g[u][2]] = 1; 
    }
    if (vis[g[u][1]] && vis[g[u][2]]) {
        if (h[g[u][1]] == h[g[u][2]] && tree[g[u][1]] == (1 << h[g[u][1]]) - 1) {
            vis[u] = 1;
            ans++;
        }
        if (h[g[u][1]] - 1 == h[g[u][2]] && tree[g[u][2]] == (1 << h[g[u][2]]) - 1) {
            vis[u] = 1;
            ans++;
        }
    }
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> g[i][1] >> g[i][2];
    }
    dfs(1);
    cout << ans;
    return 0;
}