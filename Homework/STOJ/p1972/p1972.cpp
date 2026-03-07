#include <bits/stdc++.h>
using namespace std;

struct city {
    int x, y;
}g[105];

struct node {
    int to;
    double w;
    int nxt;
}edge[100005];
int idx, head[100005];
void addEdge(int u, int v, double w) {
    edge[++idx] = {v, w, head[u]};
    head[u] = idx;
}
priority_queue<pair<double, int>, vector<pair<double, int>>,
               greater<pair<double, int>>> q;
double dist[105];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        g[i] = {x, y};
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        double d1 = g[u].x - g[v].x;
        double d2 = g[u].y - g[v].y;
        addEdge(u, v, sqrt(d1 * d1 + d2 * d2));
        addEdge(v, u, sqrt(d1 * d1 + d2 * d2));
    }
    int s, t;
    cin >> s >> t;
    for (int i = 0; i <= n + 1; i++) {
        dist[i] = 1e18;
    }
    dist[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        pair<double, int> t = q.top();
        q.pop();
        int u = t.second;
        double d = t.first;
        if (d > dist[u]) {
            continue;
        }
        for (int i = head[u]; i; i = edge[i].nxt) {
            int v = edge[i].to;
            double w = edge[i].w;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }
    cout << fixed << setprecision(2) << dist[t] << endl;
    return 0;
}