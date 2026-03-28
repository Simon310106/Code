#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;
const int MAXM = 400005;
typedef pair<int, int> PI;
int h[MAXM], e[MAXM], w[MAXM], ne[MAXM];
int idx;
int dist[MAXN];
bool vis[MAXN];
int n, m;

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int prim() {
    memset(dist, 0x3f, sizeof dist);
    memset(vis, 0, sizeof vis);
    priority_queue<PI, vector<PI>, greater<PI>> q;
    dist[1] = 0;
    q.push({0, 1});
    int sum = 0;
    int cnt = 0;
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        int u = t.second;
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        sum += t.first;
        cnt++;
        for(int i = h[u]; i != -1; i = ne[i]) {
            int v = e[i];
            if (!vis[v] && dist[v] > w[i]) {
                dist[v] = w[i];
                q.push({dist[v], v});
            }
        }
    }
    if (cnt < n) {
        return 0x3f3f3f3f;
    }
    return sum;
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    int ans = prim();
    if (ans == 0x3f3f3f3f) {
        cout << "orz" << endl;
    }
    else {
        cout << ans << endl;
    }
    return 0;
}