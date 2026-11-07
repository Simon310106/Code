#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
vector<int> g[N];
int p, c;
int low[N], dfn[N], idx, ans;
bool cutV[N];

void tarjan(int u, bool root) {
    dfn[u] = low[u] = ++idx;
    int son = 0, cut = 0;
    for (auto v : g[u]) {
        if (dfn[v] == 0) {
            son++;
            tarjan(v, false);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                if (!root) {
                    cutV[v] = true;
                    cut++;
                }
            }
        }
        else {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (root) ans = max(ans, son);
    else ans = max(ans, cut + 1);
}

int main(){
    while (cin >> p >> c && (p || c)) {
        for (int i = 1; i <= c; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int cnt = 0;
        for (int i = 0; i < p; i++) {
            if (dfn[i] == 0) {
                cnt++;
                tarjan(i, true);
            }
        }
        cout << ans + cnt - 1 << endl;
        for (int i = 0; i <= p; i++) {
            g[i].clear();
        }
        memset(low, 0, sizeof low);
        memset(dfn, 0, sizeof dfn);
        memset(cutV, 0, sizeof cutV);
        idx = ans = 0;
    }
    return 0;
}