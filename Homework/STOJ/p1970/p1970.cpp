#include <bits/stdc++.h>
using namespace std;

struct node {
    int to, w, nxt;
}edge[500005];
int idx, head[500005];
void addEdge(int u, int v, int w) {
    edge[++idx] = {v, w, head[u]};
    head[u] = idx;
}
priority_queue<pair<int, int>,
               vector<pair<int, int>>,
               greater<pair<int, int>>> q;
int dist[500005], pre[500005];
vector<int> path[500005];

int main(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    q.push({0, s});
    path[s].push_back(s);
    while(!q.empty()) {
        pair<int, int> now = q.top();
        q.pop();
        int u = now.second, d = now.first;
        if (d > dist[u]) {
            continue;
        }
        for (int i = head[u]; i; i = edge[i].nxt) {
            int v = edge[i].to, w = edge[i].w;
            vector<int> res = path[u];
            res.push_back(v);
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
                pre[v] = u;
                path[v] = res;
            }
            else if (dist[v] == dist[u] + w) {
                if (res < path[v]) {
                    pre[v] = u;
                    path[v] = res;
                }
            }
        }
    }
    if (dist[t] == 0x3f3f3f3f) {
        cout << "can’t arrive" << endl;
        return 0;
    }
    cout << dist[t] << endl;
    for (auto v : path[t]) {
        cout << v << " ";
    }
    return 0;
}