#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> g[N];
int n, m;
int low[N], dfn[N], belong[N], idx;
bool cutV[N];

void tarjan(int u, bool root) {
    dfn[u] = low[u] = ++idx;
    int son = 0;
    for (auto v : g[u]) {
        if (dfn[v] == 0) {
            son++;
            tarjan(v, false);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                if (!root || son >= 2) {
                    cutV[u] = true;
                }
            }
        }
        else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) tarjan(i, true);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (cutV[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
        if (cutV[i]) {
            cout << i << " ";
        }
    }
    return 0;
}