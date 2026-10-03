#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
vector<int> g[N], scc[N], G[N];
stack<int> st;
int dfn[N], low[N], belong[N], idx, sccCnt, from[N], to[N], a[N], bar[N], sccSum[N];
int dist[N], vis[N];

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
            sccSum[sccCnt] += a[v];
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
        from[i] = u;
        to[i] = v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int s, p;
    cin >> s >> p;
    for (int i = 1; i <= p; i++) {
        cin >> bar[i];
    }
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) tarjan(i);
    }
    s = belong[s];
    for (int i = 1; i <= p; i++) {
        bar[i] = belong[bar[i]];
    }
    for (int i = 1; i <= m; i++) {
        if (belong[from[i]] != belong[to[i]])  {
            G[belong[from[i]]].push_back(belong[to[i]]);
        }
    }
    queue<pair<int, int> > q;
    for (int i = 1; i <= sccCnt; i++) {
        dist[i] = INT_MIN;
    }
    dist[s] = sccSum[s];
    q.push({0, s});
    vis[s] = 0;
    while (!q.empty()) {
        pair<int, int> t = q.front();
        q.pop();
        int u = t.second;
        vis[u] = 0;
        for (int v : G[u]) {
            if (dist[v] < dist[u] + sccSum[v]) {
                dist[v] = dist[u] + sccSum[v];
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push({dist[v], v});
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= p; i++) {
        ans = max(ans, dist[bar[i]]);
    }
    cout << ans;
    return 0;
}