#include <bits/stdc++.h>
using namespace std;

vector<int> g[100005];
queue<int> q;
int indeg[100005], ans[100005];

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        indeg[y]++;
    }
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
            ans[i] = 1;
        }
    }
    while(!q.empty()) {
        int t = q.front(); q.pop();
        for (int v : g[t]) {
            indeg[v]--;
            ans[v] = ans[t] + 1;
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}