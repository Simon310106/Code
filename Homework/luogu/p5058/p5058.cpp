#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
vector<int> g[N], ans;
int n, a, b;
int dfn[N], low[N], idx;

void tarjan(int u) {
    dfn[u] = low[u] = ++idx;
    for (int v : g[u]) {
        if (dfn[v] == 0) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                if (dfn[b] >= dfn[v] && u != b && u != a) {
                    ans.push_back(u);
                }
            }
        }
        else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

int main(){
    cin >> n;
    int u, v;
    while (cin >> u >> v && (u || v)) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> a >> b;
    tarjan(a);
    if (ans.size() == 0) {
        cout << "No solution" << endl;
    } 
    else {
        sort(ans.begin(), ans.end());
        cout << ans[0] << endl;
    }
    return 0;
}