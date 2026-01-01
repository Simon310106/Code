#include <bits/stdc++.h>
using namespace std;

vector<int> a[500005];
int fa[500005][26];
int d[500005];
int n, m, s;

void dfs(int x, int father) {
    d[x] = d[father] + 1;
    fa[x][0] = father;
    for (int i = 1; i < 20; i++) {
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    }
    for (int i = 0; i < a[x].size(); i++) {
        int v = a[x][i];
        if (v == father) {
            continue;
        } 
        dfs(v, x);
    }
}

int find(int x, int y) {
    if (d[x] < d[y]) {
        swap(x, y);
    }
    int diff = d[x] - d[y];
    for (int i = 0; i < 20; i++) {
        if (diff & (1 << i)) {
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

int main(){
    cin >> n >> m >> s;
    while (--n) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    // fa[s][0] = 0;
    dfs(s, 0);
    while (m--) {
        int x, y;
        cin >> x >> y;
        cout << find(x, y) << endl;
    }
    return 0;
}