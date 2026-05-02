#include <bits/stdc++.h>
using namespace std;

struct node {
    int nxt, w;
};
int n, p;
int c[10005], indeg[10005], outdeg[10005], u[10005];
vector<node> g[10005];
queue<int> q;

int main(){
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &c[i], &u[i]);
    }
    for (int i = 1; i <= p; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back({v, w});
        indeg[v]++;
        outdeg[u]++;
    }
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        if (c[t] <= 0) {
            continue;
        }
        for (auto &v : g[t]) {
            int nxt = v.nxt, w = v.w;
            c[nxt] += c[t] * w;
            indeg[nxt]--;
            if (indeg[nxt] == 0) {
                c[nxt] -= u[nxt];
                q.push(nxt);
            }
        }
    }
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        if (outdeg[i] == 0 && c[i] > 0) {
            printf("%d %d\n", i, c[i]);
            flag = 0;
        }
    }
    if (flag) printf("NULL");
    return 0;
}