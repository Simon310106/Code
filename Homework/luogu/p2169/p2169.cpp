#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
vector<int> g[N], scc[N];
vector<pair<int, int>> G[N];
stack<int> st;
int n, m, from[N], to[N], times[N];
int dfn[N], low[N], belong[N], sccCnt, idx;
int dist[N];

void tarjan(int u) {
    dfn[u] = low[u] = ++idx;
    st.push(u);
    for (int v : g[u]) {
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
        while (u != v) {
            v = st.top(); st.pop();
            scc[sccCnt].push_back(v);
            belong[v] = sccCnt;
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(v);
        from[i] = u;
        to[i] = v;
        times[i] = w;
    }
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) tarjan(i);
    }
    for (int i = 1; i <= m; i++) {
        if (belong[from[i]] != belong[to[i]]) {
            G[belong[from[i]]].push_back({belong[to[i]], times[i]});
        }
    }
    memset(dist, 0x3f, sizeof dist);
    int s = belong[1], e = belong[n];
    dist[s] = 0;
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> q;
    q.push({0, s});
    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if (d > dist[u]) {
            continue;
        }
        for (auto [v, w] : G[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }
    cout << dist[e] << endl;
    return 0;
}