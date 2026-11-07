#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, k;
vector<int> g[N];
int fa[N][25], dep[N], diff[N];

void dfs(int x, int father) {
    dep[x] = dep[father] + 1;
    fa[x][0] = father;
    for (int i = 1; i < 20; i++) {
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    } 
    for (int v : g[x]) {
        if (v == father) {
            continue;
        }
        dfs(v, x);
    }
}

int find(int x, int y) {
    if (dep[x] < dep[y]) {
        swap(x, y);
    }
    int difference = dep[x] - dep[y];
    for (int i = 0; i < 20; i++) {
        if (difference & (1 << i)) {
            x = fa[x][i];
        }
    }
    if (x == y) {
        return x;
    }
    for (int i = 19; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

void solve(int u, int father) {
    for (int v : g[u]) {
        if (v == father) {
            continue;
        }
        solve(v, u);
        diff[u] += diff[v];
    }
}

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dep[1] = 1;
    dfs(1, 0);
    for (int i = 1; i <= k; i++) {
        int s, t;
        cin >> s >> t;
        int lca = find(s, t);
        diff[s]++;
        diff[t]++;
        diff[lca]--;
        diff[fa[lca][0]]--;
    }
    solve(1, 0);
    cout << *max_element(diff + 1, diff + n + 1) << endl;
    return 0;
}