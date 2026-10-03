#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

const int N = 5e3 + 5;
vector<PII> g[2*N];
queue<int> q;
int n, m;
int enter[2*N], update[2*N], d[2*N];

bool spfa() {
    memset(d, 0x3f, sizeof d);
    enter[0] = 1;
    update[0]++;
    d[0] = 0;
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
        int opr, a, b;
        cin >> opr >> a >> b;
        if (opr == 1) {
            int c;
            cin >> c;
            g[a].push_back({b, -c});
        }
        else if (opr == 2) {
            int c;
            cin >> c;
            g[b].push_back({a, c});
        }
        else {
            g[a].push_back({b, 0});
            g[b].push_back({a, 0});
        }
    }
    if (spfa()) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}