#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
vector<int> g[N], scc[N];
vector<int> G[N];
stack<int> st;
int dfn[N], low[N], belong[N], sccCnt, idx, sccSum[N];
int w[N], vis[N][N], indeg[N], dp[N];

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
            belong[v] = sccCnt;
            scc[sccCnt].push_back(v);
            sccSum[sccCnt] += w[v];
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
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
            dp[i] = sccSum[i];
        }
    } 
    while (!q.empty()) {
        int t = q.front(); q.pop();
        for (auto v : G[t]) {
            indeg[v]--;
            dp[v] = max(dp[v], dp[t] + sccSum[v]);
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
    }
    int ans = *max_element(dp + 1, dp + 1 + sccCnt);
    cout << ans << endl;
    return 0;
}