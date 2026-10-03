#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<int> g[N], scc[N];
vector<int> G[N];
stack<int> st;
int dfn[N], low[N], belong[N], sccCnt, idx, vis[N][N], indeg[N];

void tarjan(int u) {
    dfn[u] = low[u] = ++idx;
    st.push(u);
    for (auto v : g[u]) {
        if (dfn[v] == 0) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else {
            if (belong[v] == 0) {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }
    if (dfn[u] == low[u]) {
        sccCnt++;
        int v = -1;
        while (v != u) {
            v = st.top(); st.pop();
            scc[sccCnt].push_back(v);
            belong[v] = sccCnt;
        }
    }
}

int main(){
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        sccCnt = idx = 0;
        memset(dfn, 0, sizeof dfn);
        memset(low, 0, sizeof low);
        memset(belong, 0, sizeof belong);
        memset(vis, 0, sizeof vis);
        memset(indeg, 0, sizeof indeg);
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            scc[i].clear();
            G[i].clear();
            indeg[i] = 0;
        }
        while (!st.empty()) st.pop();
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
        }
        for (int i = 1; i <= n; i++) {
            if (dfn[i] == 0) tarjan(i);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < g[i].size(); j++) {
                if (belong[i] != belong[g[i][j]] && !vis[belong[i]][belong[g[i][j]]]) {
                    vis[belong[i]][belong[g[i][j]]] = 1;
                    G[belong[i]].push_back(belong[g[i][j]]);
                    indeg[belong[g[i][j]]]++;
                }
            }
        }
        queue<int> q;
        for (int i = 1; i <= sccCnt; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        bool flag = 0;
        while (!q.empty()) {
            int t = q.front();q.pop();
            for (int v : G[t]) {
                indeg[v]--;
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
            if (q.size() > 1) {
                cout << "No" << endl;
                flag = 1;
                break;
            }
        }
        if (!flag) cout << "Yes" << endl;
    }
    return 0;
}