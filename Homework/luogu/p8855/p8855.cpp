#include <bits/stdc++.h>
using namespace std;

vector<int> g[30005];
int fa[30005][26];
int dep[30005];
int n, m;
int tmp, ans;

void dfs(int x, int f) {
    dep[x] = dep[f] + 1;
    fa[x][0] = f;
    for (int i = 1; i < 20; i++) {
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    }
    for (int i = 0; i < g[x].size(); i++) {
        int v = g[x][i];
        if (v == f) {
            continue;
        }
        dfs(v, x);
    }
}

int find(int x, int y) {
    if (dep[x] < dep[y]) {
        swap(x, y);
    }
    int diff = dep[x] - dep[y];
    for (int i = 0; i < 20; i++) {
        if (diff & (1 << i)) {
            x = fa[x][i];
        }
    }
    if (x == y) {
        return x;
    }
    for (int i = 19; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

int main(){
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> m;
    dfs(1, 0);
    tmp = 1;
    while (m--) {
        int id;
        cin >> id;
        ans += dep[id] + dep[tmp] - 2 * dep[find(id, tmp)];
        tmp = id;
    }
    cout << ans;
    return 0;
}