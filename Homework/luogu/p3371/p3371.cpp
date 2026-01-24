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

int dist[500005];
priority_queue<pair<int, int>,
               vector<pair<int, int>>,
               greater<pair<int, int>>> q;

int main(){
    int n, s, m;
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    for (int i = 1; i <= n; i++) {
        dist[i] = 2147483647;
    }
    dist[s] = 0;
    q.push({0, s}); // {最短距离，结点编号}；
    while (!q.empty()) {
        // 先选当前距离最小的结点
        pair<int, int> t = q.top();
        q.pop();
        int u = t.second, d = t.first;
        if (d > dist[u]) {
            continue;// 排除已经确认过最短距离的点
        }
        // 由最小的节点更新其相连的结点
        for (int i = head[u]; i; i = edge[i].nxt) {
            int v = edge[i].to, w = edge[i].w;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    return 0;
}