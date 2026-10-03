#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

vector<PII> g[5005];
queue<int> q;
int d[5005], enter[5005], update[5005];
int n, m;

bool spfa() {
    memset(d, 0x3f, sizeof d);
    d[0] = 0;
    enter[0] = 1;
    update[0]++;
    q.push(0);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        enter[u] = 0;
        for (auto [v, w] : g[u]) {
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                if (!enter[v]) {
                    if (++update[v] > n) return false;
                    q.push(v);
                    enter[v] = 1;
                }
            }
        }
    }
    return true;
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        g[0].push_back({i, 0});
    }
    for (int i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        g[y].push_back({x, w});
    }
    if (spfa()) {
        for (int i = 1; i <= n; i++) {
            cout << d[i] << " ";
        }
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}