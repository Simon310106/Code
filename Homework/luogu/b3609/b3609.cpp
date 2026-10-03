#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, M = 1e6 + 5;
vector<int> g[N], scc[N];
stack<int> st;
int dfn[N], low[N], belong[N], idx, sccCnt, vis[N];

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
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) tarjan(i);
    }
    cout << sccCnt << endl;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            sort(scc[belong[i]].begin(), scc[belong[i]].end());
            for (auto x : scc[belong[i]]) {
                cout << x << " ";
                vis[x] = 1;
            }
            cout << endl;
        }
    }
    return 0;
}