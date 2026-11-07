#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

const int N = 5e5 + 5;
const int M = 2e6 + 5;

int low[N], dfn[N], idx;
int cutEdge[2*M], eid = 1;
vector<PII> g[N];
vector<int> ans;

void tarjan(int u, int pre) {
    dfn[u] = low[u] = ++idx;
    for (auto [e, v] : g[u]) {
        if ((e ^ 1) == pre) continue;
        if (dfn[v] == 0) {
            tarjan(v, e);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) cutEdge[e >> 1] = true;
        }
        else {
            low[u] = min(low[u], dfn[v]); //弃边无影响
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back({++eid, v});
        g[v].push_back({++eid, u});
    }
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) tarjan(i, 0);
    }
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (cutEdge[i]) {
            cnt++;
            ans.push_back(i);
        }
    }
    cout << cnt << endl;
    for (auto x : ans) cout << x << " ";
    return 0;
}