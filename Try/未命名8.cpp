#include <bits/stdc++.h>
using namespace std;

const int N = 400005;
vector<pair<int, int>> g[N];
vector<int> scc[N], dcc[N];
stack<int> st;
int n = -1, m = -1;
int dfn[N], low[N], belong[N], sccCnt, idx, eid = 1;
int from[N], to[N], Case_Number, bridge;
int fa[N], dep[N], scc_dep[N], f[N];

void tarjan(int u, int pre, int tmp) {
    dfn[u] = low[u] = ++idx;
    dep[u] = ++tmp;
    st.push(u);
    for (auto [e, v] : g[u]) {
        if ((e ^ 1) == pre) continue;
        if (dfn[v] == 0) {
            tarjan(v, e, tmp);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) {
                bridge++;
            }
        }
        else {
            low[u] = min(low[u], dfn[v]);
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

void init_dcc(int u, int father) {
    fa[u] = father;
    scc_dep[u] = scc_dep[father] + 1;
    for (auto v : dcc[u]) {
        if (v != father) {
            init_dcc(v, u);
        }
    }
}

int find(int u) {
    if (f[u] == u) return u;
    return f[u] = find(f[u]);
}

void solve(int x, int y) {
    x = find(x);
    y = find(y);
    while (x != y) {
        if (scc_dep[x] < scc_dep[y]) swap(x, y);
        f[x] = find(fa[x]);
        bridge--;
        x = find(x);
    }
}

int main(){
    freopen("try.in", "r", stdin);
    freopen("try.out", "w", stdout);
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        Case_Number++;
        for (int i = 0; i <= n; i++) {
            g[i].clear();
            scc[i].clear();
            dcc[i].clear();
        }
        memset(dfn, 0, sizeof dfn);
        memset(low, 0, sizeof low);
        memset(belong, 0, sizeof belong);
        memset(fa, 0, sizeof fa);
        memset(dep, 0, sizeof dep);
        while (!st.empty()) st.pop();
        sccCnt = idx = eid = bridge = 0;
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            from[i] = u;
            to[i] = v;
            g[u].push_back({++eid, v});
            g[v].push_back({++eid, u});
        }
        tarjan(1, 0, 0);
        for(int i = 1; i <= sccCnt; i++) f[i] = i;
        for (int i = 1; i <= m; i++) {
            if (belong[from[i]] != belong[to[i]]) {
                dcc[belong[from[i]]].push_back(belong[to[i]]);
                dcc[belong[to[i]]].push_back(belong[from[i]]);
            }
        }
        init_dcc(1, 1);
        int q;
        cin >> q;
        cout << "Case " << Case_Number << ":" << endl;
        for (int i = 1; i <= q; i++) {
            int x, y;
            cin >> x >> y;
            x = belong[x];
            y = belong[y];
            if (bridge == 0) {
                cout << bridge << endl;
                continue;
            }
            solve(x, y);
            cout << bridge << endl;
        }
        cout << endl;
    }
    return 0;
}