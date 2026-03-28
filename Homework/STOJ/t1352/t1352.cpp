#include <bits/stdc++.h>
using namespace std;

vector<int> g[20005];
queue<int> q;
int indeg[20005];
int money[20005];

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[b].push_back(a);
        indeg[a]++;
    }
    for (int i = 1; i <= n; i++){
        money[i] = 100;
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    int cnt = 0;
    while (!q.empty()) {
        int t = q.front(); q.pop();
        cnt++;
        for (int v : g[t]) {
            indeg[v]--;
            if (indeg[v] == 0) {
                q.push(v);
            }
            money[v] = max(money[v], money[t] + 1);
        }
    }
    if (cnt < n) {
        cout << "Poor Xed";
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += money[i];
    }
    cout << ans;
    return 0;
}