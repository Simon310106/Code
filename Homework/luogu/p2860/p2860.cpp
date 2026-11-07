#include <bits/stdc++.h>
using namespace std;

const int N = 5005, M = 10000;
vector<pair<int, int>> g[N], G[N];
vector<int> ebcc[N];
stack<int> st;
int f, r;
int dfn[N], low[N], idx, eid = 1, belong[N], ebccCnt;
bool cutEdge[2*M];
int from[M], to[M], deg[M];

void tarjan(int u, int pre) {
    dfn[u] = low[u] = ++idx;
    st.push(u);
    for (auto [e, v] : g[u]) {
        if ((e ^ 1) == pre) {
            continue;
        }
        if (dfn[v] == 0) {
            tarjan(v, e);
            low[u] = min(low[u], low[v]);
            if (low[u] > dfn[v]) cutEdge[e >> 1] = true;
        }
        else {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        int v = -1;
        ebccCnt++;
        while (u != v) {
            v = st.top(); st.pop();
            belong[v] = ebccCnt;
            ebcc[ebccCnt].push_back(v);
        }
    }
}

int main(){
    cin >> f >> r;
    for (int i = 1; i <= r; i++) {
        int u, v;
        cin >> u >> v;
        from[i] = u;
        to[i] = v;
        g[u].push_back({++eid, v});
        g[v].push_back({++eid, u});
    }
    tarjan(1, 0);
    for (int i = 1; i <= r; i++) {
        if (belong[from[i]] != belong[to[i]]) {
            deg[belong[from[i]]]++;
            deg[belong[to[i]]]++;
        }
    }
    int leaf = 0;
    for (int i = 1; i <= ebccCnt; i++) {
        if (deg[i] == 1) {
            leaf++;
        }
    }
    cout << (leaf + 1) / 2 << endl;
    return 0;
}