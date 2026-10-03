#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
vector<int> g[N], scc[N];
stack<int> st;
int dfn[N], low[N], belong[N], sccCnt, idx, minCost[N], minPos[N];
int a[N];

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
        while (u != v) {
            v = st.top(); st.pop();
            scc[sccCnt].push_back(v);
            belong[v] = sccCnt;
            minCost[sccCnt] = min(a[v], minCost[sccCnt]);
        }
    }
}

signed main(){
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    memset(minCost, 0x3f, sizeof minCost);
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) tarjan(i);
    }
    int cost = 0, ans = 1;
    for (int i = 1; i <= sccCnt; i++) {
        for (int j = 0; j < scc[i].size(); j++) {
            if (a[scc[i][j]] == minCost[i]) {
                minPos[i]++;
            }
        }
        cost += minCost[i];
        ans *= minPos[i];
        ans %= MOD;
    }
    cout << cost << " " << ans;
    return 0;
}