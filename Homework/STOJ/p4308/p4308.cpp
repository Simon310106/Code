#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int head[MAXN], nxt[MAXN * 2], to[MAXN * 2], idx;
int n, a, b, p, dep[MAXN];

void add(int a, int b) {
    to[++idx] = b;
    nxt[idx] = head[a];
    head[a] = idx;
}

void dfs(int u, int f) {
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v == f) continue;
        dep[v] = dep[u] + 1;
        if (dep[v] > dep[p]) p = v;
        dfs(v, u);
    }
}

int main(){
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1, 0);
    dep[p] = 0;
    dfs(p, 0);
    cout << dep[p] << endl;
    return 0;
}