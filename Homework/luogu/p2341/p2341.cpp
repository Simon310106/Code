#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5, M = 5e4 + 5;
vector<int> g[N], scc[N];
stack<int> st;
int dfn[N], low[N], belong[N], idx, sccCnt, outdegree[M];

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
        while(v != u) {
            v = st.top();
            st.pop();
            belong[v] = sccCnt;
            scc[sccCnt].push_back(v);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) tarjan(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            if (belong[i] != belong[g[i][j]]) {
                outdegree[belong[i]]++;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= sccCnt; i++) {
        if (outdegree[i] == 0) {
            if (cnt == 0) cnt = i;
            else {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    cout << scc[cnt].size() << endl;
    return 0;
}