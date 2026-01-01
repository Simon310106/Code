#include <bits/stdc++.h>
using namespace std;

int n, ans, cur = 1;
vector<int> g[205];

void dfs(int x) {
    if (g[x].empty()) {
        ans = max(ans, cur);
        return;
    }
    for (int i = 0; i < g[x].size(); i++) {
            cur++;
            dfs(g[x][i]);
            cur--;
        
    }
}

int main(){
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    dfs(1);
    cout << ans;
    return 0;
}
