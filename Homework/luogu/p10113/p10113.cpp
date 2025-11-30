#include <bits/stdc++.h>
using namespace std;

vector<int> a[500005];
int fa[500005][26];
int d[500005];
int n, m, s;

void dfs(int x, int father) {
    for (int i = 0; i < a[x].size(); i++) {
        int y = a[x][i];
        if (y == father) {
            continue;
        }
        d[y] = d[x] + 1;
        fa[y][0] = x;
        for (int i = 1; i <= log2(d[y]); i++) {
            int j = fa[y][i - 1];
            fa[y][i] = fa[j][i - 1];
        }
        dfs(y, x);
    }
}

int find(int x, int y) {
    if (d[x] < d[y]) {
        swap(x, y);
    }
    while (d[x] > d[y]) {
        int p = log2(d[x] - d[y]);
        x = fa[x][p];
    }
    if (x == y) {
        return x;
    }
    for (int p = log2(d[x]); p >= 0; p--) {
        if (fa[x][p] != fa[y][p]) {
            x = fa[x][p];
            y = fa[y][p];
        }
    }
    return fa[x][0];
}

int main(){
    cin >> n >> m >> s;
    for (int i = 1; i < n; i++) {
        int t;
        cin >> t;
        a[t].push_back(i);
        a[i].push_back(t);
    }
    fa[s][0] = 0;
    dfs(s, -1);
    for (int i = 1; i <= m; i++) {
        int m;
        cin >> m;
    }
    return 0;
}