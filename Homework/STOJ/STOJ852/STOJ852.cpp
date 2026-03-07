#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PI;
const int N = 2005, M = 10005;
struct node {
    int to, w;
};
vector<node> g[N];
int dist[N];
bool vis[N];
int cnt[N];

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    for (int s = 1; s <= n; s++) {
        for (int i = 0; i <= n; i++) {
            dist[i] = INT_MAX;
        }
        memset(cnt, 0, sizeof cnt);
        memset(vis, 0, sizeof vis);
        dist[s] = 0;
        queue<PI> q;
        q.push({0, s});
        vis[s] = 0;
        while (!q.empty()) {
            PI t = q.front();
            q.pop();
            int u = t.second;
            vis[u] = 0;
            for (node &x : g[u]) {
                int v = x.to, w = x.w;
                if (dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    cnt[v] = cnt[u] + 1;
                    if (cnt[v] > n) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                    if (!vis[v]) {
                        vis[v] = 1; 
                        q.push({dist[v], v});
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}