#include <bits/stdc++.h>
using namespace std;

long long n, vis[100005], ans, dis[100005], maxdis = -0x3f3f3f3f;
vector<pair<int, long long> > a[100005];

void dfs(int x) {
    vis[x] = 1;
    for (int i = 0; i < a[x].size(); i++) {
        if (!vis[a[x][i].first]) {
            dis[a[x][i].first] = dis[x] + a[x][i].second;
            maxdis = max(maxdis, dis[a[x][i].first]);
            ans += a[x][i].second * 2;
            dfs(a[x][i].first);
        }
    }
}

int main(){
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        a[u].push_back({v, l});
        a[v].push_back({u, l});
    }
    dfs(1);
    cout << ans - maxdis << endl;
    return 0;
}