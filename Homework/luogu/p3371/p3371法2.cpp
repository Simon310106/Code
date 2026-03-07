#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int, int> PI;

const int N = 1e4 + 5, M = 5e5 + 5;
const int INF = 0x3f3f3f3f;
struct node {
    int to, w;
};
vector<node> g[N];
int dist[M];
bool vis[M];

signed main(){
    int n, m, s;
    scanf("%lld %lld %lld", &n, &m, &s);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        g[u].push_back({v, w});
    }
    for (int i = 0; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    dist[s] = 0;
    // SPFA
    queue<PI> q;
    q.push({0, s});
    vis[s] = 0;
    while (!q.empty()) {
        PI t = q.front();
        q.pop();
        int u = t.second;
        vis[u] = 0;
        for (node &x : g[u]) {               // 遍历所有出边
            int v = x.to, w = x.w;
            if (dist[v] > dist[u] + w) {    // 松弛操作
                dist[v] = dist[u] + w;
                if (!vis[v]) {               // 不重复入队
                    vis[v] = 1;
                    q.push({dist[v], v});
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld ", dist[i]);
    }
    return 0;
}