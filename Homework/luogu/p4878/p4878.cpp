#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

const int N = 1e3+5;
vector<PII> g[N];
queue<int> q;
int d[N], enter[N], update[N];
int n, ml, md;
bool vis[N];

int spfa(int s) {
    memset(d, 0x3f, sizeof d);
    memset(enter, 0, sizeof enter);
    memset(update, 0, sizeof update);
    d[s] = 0;
    enter[s] = 1;
    update[s]++;
    q.push(s);
    vis[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        enter[u] = 0;
        for (auto [v, w] : g[u]) {
            if (d[u] + w < d[v]) {
                vis[v] = 1;
                d[v] = d[u] + w;
                if (!enter[v]) {
                    if (++update[v] > n) return -1;
                    q.push(v);
                    enter[v] = 1;
                }
            }
        }
    }
    if (!vis[n] || d[n] == 0x3f3f3f3f) {
        return -2;
    }
    return d[n];
}

int main(){
    // freopen("P4878_6.in", "r", stdin);
    // freopen("P4878.out", "w", stdout);
    cin >> n >> ml >> md;
    for (int i = 1; i <= n; i++) {
        g[0].push_back({i, 0});
    }
    for (int i = 1; i < n; i++) {
        g[i + 1].push_back({i, 0});
    }
    for (int i = 1; i <= ml; i++) {
        int a, b, d;
        // b - a <= d --> a >= b - d
        cin >> a >> b >> d;
        g[a].push_back({b, d});
    }
    for (int i = 1; i <= md; i++) {
        int a, b, d;
        // b - a >= d --> b >= d + a;
        cin >> a >> b >> d;
        g[b].push_back({a, -d});
    }
    if (spfa(0) == -1) {
        cout << -1 << endl;
    }
    else if (spfa(1) == -2) {
        cout << -2 << endl;
    }
    else {
        cout << spfa(1) << endl;
    }
    return 0;
}