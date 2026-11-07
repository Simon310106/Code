#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

const int N = 5e5 + 5, M = 2e6 + 5;
int dfn[N], low[N], idx;
int eid = 1;
vector<PII> g[N];
stack<int> st;
vector<int> scc[N];
int belong[N], sccCnt, vis[N];

void tarjan(int u, int pre) {
    dfn[u] = low[u] = ++idx;
    st.push(u);
    for (auto [e, v] : g[u]) {
        if ((e ^ 1) == pre) continue;
        if (dfn[v] == 0) {
            tarjan(v, e);
            low[u] = min(low[u], low[v]);
        }
        else {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        sccCnt++;
        int v = -1;
        while (u != v) {
            v = st.top(); st.pop();
            belong[v] = sccCnt;
            scc[sccCnt].push_back(v);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back({++eid, v});
        g[v].push_back({++eid, u});
    }
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) tarjan(i, 0);
    }
    cout << sccCnt << endl;
    for (int i = 1; i <= sccCnt; i++) {
        cout << scc[i].size() << " ";
        for (int j = 0; j < scc[i].size(); j++) {
            cout << scc[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}