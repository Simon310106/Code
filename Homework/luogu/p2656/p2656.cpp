#include <bits/stdc++.h>
#define int long long
using namespace std;
using PII = pair<int, int>;

const int N = 2e5 + 5;
vector<PII> g[N], G[N];
vector<PII> mushroom[N];
vector<int> scc[N];
stack<int> st;
int dfn[N], low[N], belong[N], sccCnt, idx, sccSum[N], ans;
int from[N], to[N], original[N];
bool flag[N];
int dist[N];

void tarjan(int u) {
    dfn[u] = low[u] = ++idx;
    st.push(u);
    for (auto [v, w] : g[u]) {
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

signed main(){
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w, b, sum = 0;
        double back;
        cin >> u >> v >> w >> back;
        mushroom[u].push_back({v, w});
        original[i] = w;
        from[i] = u;
        to[i] = v;
        b = back * 10;
        while (w != 0) {
            sum += w;
            w = w * b / 10.0;
        }
        g[u].push_back({v, sum});
    }
    int s;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) tarjan(i);
    }
    s = belong[s];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            if (belong[i] == belong[g[i][j].first]) {
                sccSum[belong[i]] += g[i][j].second;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if (belong[from[i]] != belong[to[i]]) {
            G[belong[from[i]]].push_back({belong[to[i]], original[i]});
        }
    }
    for (int i = 0; i <= sccCnt; i++) {
        dist[i] = INT_MIN;
    }
    dist[s] = sccSum[s];
    queue<PII> q;
    q.push({0, s});
    flag[s] = 0;
    while (!q.empty()) {
        PII t = q.front();
        q.pop();
        int u = t.second;
        flag[u] = 0;
        for (auto [v, w] : G[u]) {
            if (dist[v] < dist[u] + w + sccSum[v]) {
                dist[v] = dist[u] + w + sccSum[v];
                if (!flag[v]) {
                    flag[v] = 1;
                    q.push({dist[v], v});
                }
            }
        }
    }
    for (int i = 0; i <= sccCnt; i++) {
        ans = max(ans, dist[i]);
    }
    cout << ans;
    return 0;
}