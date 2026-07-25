#include <bits/stdc++.h>
#define int long long
#define PI pair<int, int>
using namespace std;

const int N = 1e4 + 5;
int n, m, b;
int f[N], dist[N];
struct node{
    int to, c;
};
vector <node> e[N];

bool check(int x){
    if (f[1] > x || f[n] > x) return 0;
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PI, vector<PI>, greater<PI>> q;
    dist[1] = 0;
    q.push({0, 1});
    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : e[u]) {
            if (f[v] <= x && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }
    return dist[n] <= b;
}

signed main(){
    cin >> n >> m >> b;
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        e[a].push_back({b, c});
        e[b].push_back({a, c});
    }
    int l = -1, r = 1e9 + 1;
    while (l + 1 != r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    if (r == 1e9 + 1) cout << "AFK" << endl;
    else cout << r << endl;
    return 0;
}