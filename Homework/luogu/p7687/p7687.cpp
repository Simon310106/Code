#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

const int N = 1e5 + 5;
const int M = 2e6 + 5;
int low[N], dfn[N], idx, k, l;
int eid = 1, cnt;
int cntA[2*M], cntB[2*M];
vector<PII> g[N];
vector<PII> ans;

void tarjan(int u, int pre) {
    dfn[u] = low[u] = ++idx;
    for (auto [e, v] : g[u]) {
        if ((e ^ 1) == pre) continue;
        if (dfn[v] == 0) {
            tarjan(v, e);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u] && (cntA[v] == k || cntB[v] == l || !cntA[v] || !cntB[v])) {
                cnt++;
                ans.push_back({u, v});
            }
            cntA[u] += cntA[v];
            cntB[u] += cntB[v];
        }
        else {
            low[u] = min(low[u], dfn[v]); //Æú±ßÎÞÓ°Ïì
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m >> k >> l;
    for (int i = 1; i <= k; i++) {
        int u;
        cin >> u;
        cntA[u] = 1;
    }
    for (int i = 1; i <= l; i++) {
        int u;
        cin >> u;
        cntB[u] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back({++eid, v});
        g[v].push_back({++eid, u});
    }
    tarjan(1, 0);
    cout << cnt << endl;
    for (auto [u, v] : ans) cout << u << " " << v << endl;
    return 0;
}