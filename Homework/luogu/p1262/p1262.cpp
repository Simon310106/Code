#include <bits/stdc++.h>
using namespace std;

const int N = 8005;
vector<int> g[N], scc[N];
stack<int> st;
int dfn[N], low[N], belong[N], idx, sccCnt, minCost[N], cost[N], indegree[N];
vector<int> cannot;

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
        int v = -1, mi = 0x3f3f3f3f;
        while (v != u) {
            v = st.top(); st.pop();
            belong[v] = sccCnt;
            if (cost[v] != 0) mi = min(mi, cost[v]);
            scc[sccCnt].push_back(v);
            
        }
        minCost[sccCnt] = mi;
    }
}

int main(){
    int n;
    cin >> n;
    int p;
    cin >> p;
    for (int i = 1; i <= p; i++) {
        int id, money;
        cin >> id >> money;
        cost[id] = money;
    }
    int r;
    cin >> r;
    for (int i = 1; i <= r; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (cost[i] && dfn[i] == 0) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (belong[i] == 0) {
            cout << "NO" << endl;
            cout << i << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            if (belong[i] != belong[g[i][j]]) {
                indegree[belong[g[i][j]]]++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= sccCnt; i++) {
        if (indegree[i] == 0) {
            ans += minCost[i];
        }
    }
    cout << "YES" << endl << ans << endl;
    return 0;
}