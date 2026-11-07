#include <bits/stdc++.h>
#define int long long
using namespace std;

using PII = pair<int, int>;

const int N = 2e5 + 5;
vector<PII> g[N], G[N];
vector<int> scc[N];
stack<int> st;
int n, k, from[N], to[N], dp[N], edgeCnt, w[N], in[N];
int dfn[N], low[N], belong[N], sccCnt, idx;

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
        while (u != v) {
            v = st.top(); st.pop();
            belong[v] = sccCnt;
            scc[sccCnt].push_back(v);
        }
    }
}

signed main(){
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        int x, a, b;
        cin >> x >> a >> b;
        if (x == 1) {
            g[a].push_back({b, 0});
            from[++edgeCnt] = a;
            w[edgeCnt] = 0;
            to[edgeCnt] = b;
            w[edgeCnt] = 0;
            g[b].push_back({a, 0});
            from[++edgeCnt] = a;
            w[edgeCnt] = 0;
            to[edgeCnt] = b;
            w[edgeCnt] = 0;
        }
        else if (x == 2) {
            g[a].push_back({b, 1});
            from[++edgeCnt] = a;
            w[edgeCnt] = 1;
            to[edgeCnt] = b;
            w[edgeCnt] = 1;
        }
        else if (x == 3) {
            g[b].push_back({a, 0});
            from[++edgeCnt] = b;
            w[edgeCnt] = 0;
            to[edgeCnt] = a;
            w[edgeCnt] = 0;
        }
        else if (x == 4) {
            g[b].push_back({a, 1});
            from[++edgeCnt] = b;
            w[edgeCnt] = 1;
            to[edgeCnt] = a;
            w[edgeCnt] = 1;
        }
        else if (x == 5) {
            g[a].push_back({b, 0});
            from[++edgeCnt] = a;
            w[edgeCnt] = 0;
            to[edgeCnt] = b;
            w[edgeCnt] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) tarjan(i);
    }
    for (int i = 1; i <= edgeCnt; i++) {
        int u = belong[from[i]], v = belong[to[i]];
        if (u == v && w[i] == 1) {
            cout << -1 << endl;
            return 0;
        }
        if (u != v) {
            G[u].push_back({v, w[i]});
            in[v]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= sccCnt; i++) {
        if (in[i] == 0) {
            q.push(i);
            dp[i] = 1;
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, w] : G[u]) {
            in[v]--;
            dp[v] = max(dp[v], dp[u] + w);
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= sccCnt; i++) {
        ans += dp[i] * scc[i].size();
    }
    cout << ans << " ";
    return 0;
}