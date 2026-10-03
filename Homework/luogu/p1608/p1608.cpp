#include <bits/stdc++.h>
using namespace std;

using PII = pair<int, int>;
const int N = 1e6 + 5;
vector<PII> g[N];
int dist[N];
int ans[N];

int main(){
    int n, e;
    cin >> n >> e;
    for (int i = 1; i <= e; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    dist[1] = 0;
    ans[1] = 1;
    q.push({0, 1});
    while (!q.empty()) {
        auto [d, u] = q.top(); q.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                ans[v] = ans[u];
                q.push({dist[v], v});
            }
            else if (dist[u] + w == dist[v]) {
                ans[v] += ans[u];
            }
        }
    }
    if (ans[n] == 0) cout << "No answer" << endl;
    else {
        cout << dist[n] << " " << ans[n] << endl;
    }
    return 0;
}