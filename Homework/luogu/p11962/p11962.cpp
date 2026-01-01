#include <bits/stdc++.h>
using namespace std;

int n, cnt[2];
int dis[200005];
vector<int> g[200005];

void dfs(int x, int fa) {
    dis[x] = dis[fa] + 1;
    cnt[dis[x] & 1]++;
    for (int i = 0; i < g[x].size(); i++) {
        int tmp = g[x][i];
        if (tmp == fa) continue;
        dfs(tmp, x);
    }
}

int main(){
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << cnt[dis[i] & 1] << " ";
    }

    return 0;
}