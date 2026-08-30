#include <bits/stdc++.h>
using namespace std;

using PII = pair<int, int>;
const int N = 1e6 + 5, mod = 1e5 + 3;
vector<int> g[N];
int dist[N];
int ans[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);;
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    dist[1] = 0;
    ans[1] = 1;
    q.push({0, 1}); // ³¤¶È£¬±àºÅ
    while (!q.empty()) {
        auto [d, u] = q.top();q.pop();
        if (d > dist[u]) continue;
        for (auto v : g[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                ans[v] = ans[u];
                q.push({dist[v], v});
            }
            else if (dist[u] + 1 == dist[v]) {
                ans[v] += ans[u];
                ans[v] %= mod;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}