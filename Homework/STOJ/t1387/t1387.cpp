#include <bits/stdc++.h>
#define c first
#define d second
using namespace std;

typedef pair<int, int> PI;
vector<pair<int, PI>> fa;
int co[10005], we[10005], dp[10005];

pair<int, PI> find(pair<int, PI> a) {
    if (fa[a.first] == a) {
        return a;
    }
    return fa[a.first] = find(fa[a.first]);
}

void Union(pair<int, PI> a, pair<int, PI> b) {
    pair<int, PI> x = find(a), y = find(b);
    if (x != y) {
        fa[y.first] = x;
        fa[y.first].second.d += y.second.d;
        fa[y.first].second.c += y.second.c;
    }
}

int main(){
    int n, m, w;
    cin >> n >> m >> w;
    int cnt = 0;
    fa.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        fa[i] = {i, {a, b}};
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        Union(fa[u], fa[v]);
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << fa[i].first << " ";
    // }
    // cout << endl;
    for (int i = 1; i <= n; i++) {
        if (fa[i].first == i) {
            cnt++;
            we[cnt] = fa[i].second.d;
            co[cnt] = fa[i].second.c;
            // cout << cnt << " " << we[cnt] << " " << co[cnt] << endl;
        }
    }
    for (int i = 1; i <= cnt; i++) {
        for (int j = w; j >= we[i]; j--) {
            dp[j] = max(dp[j], dp[j - co[i]] + we[i]);
        }
    }
    cout << dp[cnt];
    return 0;
}