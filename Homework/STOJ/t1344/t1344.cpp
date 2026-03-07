#include <bits/stdc++.h>
using namespace std;

const int N = 2005, M = 2000005;
struct node {
    int to;
    double w;
    int nxt;
}edge[M];
int idx, head[M];
void addEdge(int u, int v, double w) {
    edge[++idx] = {v, w, head[u]};
    head[u] = idx;
}
double dist[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        double w;
        cin >> u >> v >> w;
        addEdge(u, v, w * 1.0);
        addEdge(v, u, w * 1.0);
    }
    int s, t;
    cin >> s >> t;
    for (int i = 0; i <= n; i++) {
        dist[i] = 1e108;
    } 
    dist[s] = 100;
    for (int i = 1; i < n; i++) {
        bool flag = 0;
        for (int j = 1; j <= n; j++) {
            for (int k = head[j]; k; k = edge[k].nxt) {
                int v = edge[k].to;
                double w = edge[k].w;
                if (dist[v] > dist[j] / (1.0 - 0.01 * w)) {
                    dist[v] = dist[j] / (1.0 - 0.01 * w);
                    flag = 1;
                }
            }
        }
        if (!flag) break;
    }
    cout << fixed << setprecision(8) << dist[t];
    return 0;
}