#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int> g[N], scc[N], G[N];
stack<int> st;
int n, m;
int price[N];
int dfn[N], low[N], belong[N], sccCnt, idx, sccMax[N], sccMin[N];
int edge, from[10 * N], to[10 * N], indeg[N], dp[N], pathMax[N], pathMin[N];

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
        while (v != u) {
            v = st.top(); st.pop();
            belong[v] = sccCnt;
            scc[sccCnt].push_back(v);
            sccMin[sccCnt] = min(sccMin[sccCnt], price[v]);
            sccMax[sccCnt] = max(sccMax[sccCnt], price[v]);
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> price[i];
    }
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back(y);
        from[++edge] = x;
        to[edge] = y;
        if (z == 2) {
            g[y].push_back(x);
            from[++edge] = y;
            to[edge] = x;
        }
    }
    memset(sccMin, 0x3f, sizeof sccMin);
    memset(sccMax, -0x3f, sizeof sccMax);
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) tarjan(i);
    }
    for (int i = 1; i <= edge; i++) {
        if (belong[from[i]] != belong[to[i]]) {
            G[belong[from[i]]].push_back(belong[to[i]]);
            indeg[belong[to[i]]]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= sccCnt; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
        dp[i] = INT_MIN;
        pathMin[i] = INT_MAX;
    }
    int s = belong[1];
    dp[s] = sccMax[s] - sccMin[s];
    pathMin[s] = sccMin[s];
    while (!q.empty()) {
        int t = q.front(); q.pop();
        for (auto v : G[t]) {
            indeg[v]--;
            if (pathMin[t] != INT_MAX) {
                pathMin[v] = min(pathMin[v], min(pathMin[t], sccMin[v]));
                dp[v] = max({dp[v], sccMax[v] - pathMin[v], dp[t]});
            }
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
    }
    cout << dp[belong[n]] << endl;
    return 0;
}