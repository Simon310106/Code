#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int head[MAXN], nxt[MAXN * 2], to[MAXN * 2], idx;
int r[MAXN];
int n, a, b, ans = INT_MAX;

void add(int a, int b) {
    to[++idx] = b;
    nxt[idx] = head[a];
    head[a] = idx;
}

int dfs(int u, int f) {
    int sum = 1, res = 0;
    for (int i = head[u]; i != -1; i = nxt[i]) {
        int v = to[i];
        if (v == f) continue;
        int t = dfs(v, u);
        sum += t;
        res = max(res, t);
    }
    res = max(res, n - sum);
    r[u] = res;
    ans = min(ans, res);
    return sum;
}

int main(){
    cin >> n;
    memset(head, -1, sizeof(head));
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        if (r[i] == ans) {
            cout << i << " ";
        }
    }
    return 0;
}