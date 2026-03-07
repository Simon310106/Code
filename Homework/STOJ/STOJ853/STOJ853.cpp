#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PI;
const int N = 505, M = 10005;

struct node {
    int to, w;
};
vector<node> g[M];
int dist[N], cnt[N];
bool vis[M];

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u != v)
            g[u].push_back({v, w});
    }
    if (k == 0) {
        cout << "impossible";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    dist[1] = 0;
    queue<PI> q;
    vis[1] = 0;
    q.push({0, 1});
    while (!q.empty()) {
        PI t = q.front();
        q.pop();
        int u = t.second;
        vis[u] = 0;
        for (node &x : g[u]) {
            int v = x.to, w = x.w;
            // cnt[v] = cnt[u];
            if (dist[v] > dist[u] + w && cnt[u] + 1 <= k) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1;
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push({dist[v], v});
                }
            }
        }
    }
    if (dist[n] == INT_MAX) {
        cout << "impossible";
        return 0;
    }
    cout << dist[n];
    return 0;
}