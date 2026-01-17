#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int n, k, p, dep[MAXN], dia, fa[MAXN];
int head[MAXN], nxt[2 * MAXN], to[2 * MAXN], w[2 * MAXN], idx;
int d1[MAXN], d2[MAXN], ans;
bool vis[MAXN];

void add(int a, int b) {
    to[++idx] = b;
    w[idx] = 1;
    nxt[idx] = head[a];
    head[a] = idx;
}

void dfs(int u, int f) {
    fa[u] = f;
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v == f) {
            continue;
        }
        dep[v] = dep[u] + 1;
        if (dep[v] > dep[p]) {
            p = v;
        }
        dfs(v, u);
    }
}

void dp(int u, int f) {
    d1[u] = d2[u] = 0;
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v == f) continue;
        if (vis[v] && vis[u]) w[i] = -1;
        dp(v, u);
        if (d1[v] + w[i] >= d1[u]) {
            d2[u] = d1[u];
            d1[u] = d1[v] + w[i];
        } else if (d1[v] + w[i] > d2[u]) {
            d2[u] = d1[v] + w[i];
        }
    }
    ans = max(ans, d1[u] + d2[u]);
}


int main(){
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }

    dfs(1, 0);
    dep[p] = 0;
    dfs(p, 0);
    dia = dep[p];

    if (k == 1) {
        cout << 2 * (n - 1) - dia + 1 << endl;
        return 0;
    }

    for (int i = p; i; i = fa[i]) {
        vis[i] = 1;
    }
    memset(dep, 0, sizeof(dep));
    dp(1, 0);
    cout << 2 * (n - 1) - dia - ans + 2 << endl;
    return 0;
}