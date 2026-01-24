#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, ans = 0x3f3f3f3f, c[100005];
vector <int> g[100005];

int dfs(int u) {
    if (g[u].size() == 0) {
        return c[u];
    }
    int res = 0;
    for (int i = 0; i < g[u].size(); i++) {
        res += dfs(g[u][i]);
    }
    return ans = min(res, c[u]);
}

signed main(){
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int f;
        cin >> f;
        g[f].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    cout << dfs(1) << endl;
    return 0;
}