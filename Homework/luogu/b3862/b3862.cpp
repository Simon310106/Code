#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 1005;

vector<int> adj[N];
bool vis[N];
int maxn;

void dfs(int u) {
    vis[u] = true;
    maxn = max(maxn, u);
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i]; 
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        memset(vis, false, sizeof(vis));
        maxn = i;
        dfs(i);
        cout << maxn << " ";
    }
    cout << endl;
    return 0;
}