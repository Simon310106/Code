#include <bits/stdc++.h>
using namespace std;

struct node {
    int to, w, nxt;
}edge[55];

int idx, head[55];

void addEdge(int u, int v, int w) {
    edge[++idx] = {v, w, head[u]};
    head[u] = idx;
}

int dist[55];
priority_queue<pair<int, int>,
               vector<pair<int, int>>,
               greater<pair<int, int>>> q;

int main(){
    int n, s;
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int t;
            cin >> t;
            if (t != 0) {
                addEdge(i, j, t);
            }
        }
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    q.push({0, s}); // {最短距离，结点编号}；
    while (!q.empty()) {
        // 先选当前距离最小的结点
        pair<int, int> t = q.top();
        q.pop();
        int u = t.second, d = t.first;
        if (d > dist[u]) {
            continue;
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
        if (i == s) {
            continue;
        }
        else {
            if (dist[i] == 0x3f3f3f3f) {
                cout << "-1 ";
            }
            else {
                cout << dist[i] << " ";
            }
        }
    }
    return 0;
}