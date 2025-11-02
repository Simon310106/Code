#include <bits/stdc++.h>
using namespace std;

int n, d;
vector<int> g[100005];
int dis[100005];
queue<int> q;

void bfs(int x) {
    memset(dis, -1, sizeof(dis));
    dis[x] = 0;
    q.push(x);
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        for (int i = 0; i < g[c].size(); i++) {
            if (dis[g[c][i]] == -1) {
                dis[g[c][i]] = dis[c] + 1;
                if (dis[g[c][i]] <= d) {
                    q.push(g[c][i]);
                }
            }
        }
    }
}

int main(){
    cin >> n >> d;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dis[i] <= d && dis[i] > 0) {
            ans++;
        }
    }
    cout << ans;

    return 0;
}