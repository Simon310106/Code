#include <bits/stdc++.h>
using namespace std;

int n, fa[55], dep[55];
bool vis[55];
vector<int> g[55];

void dfs(int x) {
    vis[x] = 1;
    for (int i = 0; i < g[x].size(); i++) {
        if (!vis[g[x][i]]) {
            fa[g[x][i]] = x;
            dep[g[x][i]] = dep[x] + 1;
            dfs(g[x][i]);
        }
    }
}

int main(){
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dep[1] = 1;
    dfs(1);
    for (int i = 2; i <= n; i++) {
        cout << i << " " << fa[i] << " " << dep[i] << endl;
    }
    return 0;
}