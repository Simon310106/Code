#include <bits/stdc++.h>
using namespace std;

int n, m, vis[1000005];
vector<int> a[1000005];
queue<int> q;

void dfs(int x, int step) {
    vis[x] = 1;
    cout << x << " ";
    if (step == n) {
        return;
    }
    for (int i = 0; i < a[x].size(); i++) {
        if (!vis[a[x][i]]) {
            dfs(a[x][i], step + 1);
        }
    }
}

void bfs(int x) {
    memset(vis, 0, sizeof(vis));
    vis[x] = 1;
    q.push(x);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int i = 0; i < a[u].size(); i++) {
            if (!vis[a[u][i]]) {
                vis[a[u][i]] = 1;
                q.push(a[u][i]);
            }
        }
    }
}
 
int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        sort(a[i].begin(), a[i].end());
    }
    dfs(1, 0);
    cout << endl;
    bfs(1);
    cout << endl;
    return 0;
}