#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
vector<int> g[N], vbcc[2*N];
stack<int> st;
int n, m;
int idx, dfn[N], low[N], vbccCnt;

void tarjan(int u) {
    dfn[u] = low[u] = ++idx;
    st.push(u);
    for (int v : g[u]) {
        if (dfn[v] == 0) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                vbccCnt++;
                vbcc[vbccCnt].push_back(u);
                int t = -1;
                while (t != v) {
                    t = st.top();
                    st.pop();
                    vbcc[vbccCnt].push_back(t);
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
        if (u == v) continue;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) {
            if (g[i].size() == 0) {
                vbccCnt++;
                vbcc[vbccCnt].push_back(i);
            }
            else {
                tarjan(i);
            }
        }
    }
    cout << vbccCnt << endl;
    for (int i = 1; i <= vbccCnt; i++) {
        cout << vbcc[i].size() << " ";
        for (int u : vbcc[i]) {
            cout << u << " ";
        }
        cout << endl;
    }
    return 0;
}