#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;
vector<int> g[N], scc[N];
stack<int> st;
int n, m, dfn[N], low[N], belong[N], sccCnt, idx, vis[N];

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
        }
    }
}

int main(){
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) tarjan(i);
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