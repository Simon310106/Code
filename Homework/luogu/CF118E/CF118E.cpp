#include <bits/stdc++.h>
using namespace std;

using PII = pair<int, int>;

const int N = 3e5 + 5;
vector<PII> g[N], ans;
map<PII, bool> mp;
int n, m;
int low[N], dfn[N], eid = 1, idx;
bool flag = 0;

void tarjan(int u, int pre) {
    if (flag) return;
    dfn[u] = low[u] = ++idx;
    for (auto [v, e] : g[u]) {
        if ((e ^ 1) == pre) continue;
        if (dfn[v] == 0) {
            ans.push_back({u, v});
            mp[{u, v}] = true;
            mp[{v, u}] = true;
            tarjan(v, e);
            if (flag) return;
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) {
                cout << "0" << endl;
                flag = 1;
                return;
            }
        }
        else {
            low[u] = min(low[u], dfn[v]);
            if (!mp[{u, v}] && !mp[{v, u}]) {
                ans.push_back({u, v});
                mp[{u, v}] = true;
                mp[{v, u}] = true;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, ++eid});
        g[v].push_back({u, ++eid});
    }
    tarjan(1, 0);
    if (flag == 1) return 0;
    for (auto [u, v] : ans) {
        cout << u << " " << v << endl;
    }
    return 0;
}