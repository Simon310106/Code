#include <bits/stdc++.h>
#include <print>
using namespace std;

const int N = 1e4 + 5;
const int M = 5e4 + 5;
vector<pair<int, int>> g[N];
vector<int> G[N];
map<pair<int, int>, bool> mp;
stack<int> st;
int n, m, from[M], to[M];
int dfn[N], low[N], belong[N], ebccCnt, eid = 1, idx;
int fa[N][20], dep[N];
bool cutEdge[2*M];

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
            if (low[v] > dfn[u]) cutEdge[e >> 1] = true;
        }
        else {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        ebccCnt++;
        int v = -1;
        while (u != v) {
            v = st.top(); st.pop();
            belong[v] = ebccCnt;
        }
    }
}

void dfs(int u, int father) {
    dep[u] = dep[father] + 1;
    fa[u][0] = father;
    for (int i = 1; i < 15; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (int v : G[u]) {
        if (v != father) {
            dfs(v, u);
        }
    }
}

int find(int x, int y) {
    if (dep[x] < dep[y]) {
        swap(x, y);
    }
    int diff = dep[x] - dep[y];
    for (int i = 0; i < 15; i++) {
        if (diff & (1 << i)) {
            x = fa[x][i];
        }
    }
    if (x == y) {
        return x;
    }
    for (int i = 14; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        from[i] = u;
        to[i] = v;
        if (u > v) swap(u, v);
        if (mp[{u, v}]) continue;
        g[u].push_back({++eid, v});
        g[v].push_back({++eid, u});
        mp[{u, v}] = true;
    }
    tarjan(1, 0);
    for (int i = 1; i <= m; i++) {
        if (belong[from[i]] != belong[to[i]]) {
            G[belong[from[i]]].push_back(belong[to[i]]);
            G[belong[to[i]]].push_back(belong[from[i]]);
        }
    }
    dfs(1, 0);
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int dist = dep[belong[x]] + dep[belong[y]] - 2 * dep[find(belong[x], belong[y])] + 1;
        print("{:b}\n", dist);
    }
    return 0;
}