#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, M = 3e5 + 5;
vector<int> g[N], scc[N], G[N];
stack<int> st;
map<pair<int, int>, bool> mp;
int n, m;
int dfn[N], low[N], belong[N], sccCnt, idx;
int in[N], from[N], to[N];

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
            scc[sccCnt].push_back(v);
            belong[v] = sccCnt;
        }
    }
}

bool check(int u) {
    if (in[u] > 0 || scc[u].size() > 1) return 0;
    if (G[u].size() == 0) return true;
    for (auto v : G[u]) {
        if (in[v] == 1) return 0;
    }
    return 1;
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        from[i] = u;
        to[i] = v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (belong[from[i]] != belong[to[i]]) {
            if (mp[{belong[from[i]], belong[to[i]]}]) continue;
            G[belong[from[i]]].push_back(belong[to[i]]);
            in[belong[to[i]]]++;
            mp[{belong[from[i]], belong[to[i]]}] = 1;
        }
    }
    int k = 0;
    for (int i = 1; i <= sccCnt; i++) {
        if (!in[i]) {
            k++;
        }
    }
    for (int i = 1; i <= sccCnt; i++) {
        if (check(i)) {
            k--;
            break;
        }
    }
    cout << fixed << setprecision(6) << 1.0 - k * 1.0 / n << endl;
    return 0;
}