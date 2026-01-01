#include <bits/stdc++.h>
using namespace std;

int n, dep[205], s[205], fa[205];
bool vis[205];
vector<int> g[205];

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

void dfs2(int x) {
    s[x] = 1;
    for (int i = 0; i < g[x].size(); i++) {
        if (fa[g[x][i]] == x) {
            dfs2(g[x][i]);
            s[x] += s[g[x][i]];
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
    dfs2(1);
    for (int i = 1; i <= n; i++) {
        cout << s[i] << " " << dep[i] << endl;
    }
    return 0;
}