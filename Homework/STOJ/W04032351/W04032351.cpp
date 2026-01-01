#include <bits/stdc++.h>
using namespace std;

int n, m;
bool vis[1005], flag;
vector<int> g[1005];

void dfs(int x) {
    if (flag) return;
    if (vis[x]) {
        flag = 1;
        return;
    }
    vis[x] = 1;
    for (int i = 0; i < g[x].size(); i++) {
        dfs(g[x][i]);
        vis[g[x][i]] = 0;
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    dfs(1);
    if (!flag) cout << "no";
    else cout << "yes";
    return 0;
}