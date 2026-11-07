#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> g[N], vbcc[2*N];
stack<int> st;
bool cutV[N];
int dfn[N], low[N], idx, vbccCnt;

void tarjan(int u, bool root) {
    dfn[u] = low[u] = ++idx;
    st.push(u);
    int son = 0;
    for(int v : g[u]) {
        if (dfn[v] == 0) {
            son++;
            tarjan(v, false);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                if (!root || son >= 2) {
                    cutV[u] = true;
                }
                vbccCnt++;
                vbcc[vbccCnt].push_back(u);
                int t = -1;
                while (t != v) {
                    t = st.top();
                    st.pop();
                    vbcc[vbccCnt].push_back(t);
                }
            }
        }
        else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

int main(){
    int m, T = 0;
    while (cin >> m && m) {
        int n = -1;
        T++;
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            n = max({u, v, n});
            g[u].push_back(v);
            g[v].push_back(u);
        }
        tarjan(1, 1);
        long long ans = 0, sum = 1;
        if (vbccCnt == 1) {
            ans = 2;
            sum = 1LL * n * (n - 1) / 2;
        }
        else {
            for (int i = 1; i <= vbccCnt; i++) {
                int cut = 0;
                for (auto x : vbcc[i]) {
                    if (cutV[x]) cut++;
                }
                if (cut == 1) {
                    ans++;
                    sum = sum * (vbcc[i].size() - 1);
                }
            }
        }
        printf("Case %d: %lld %lld\n", T, ans, sum);
        for (int i = 0; i <= n; i++) {
            g[i].clear();
            vbcc[i].clear();
            cutV[i] = 0;
        }
        memset(dfn, 0, sizeof dfn);
        memset(low, 0, sizeof low);
        idx = vbccCnt = 0;
    }
    return 0;
}