#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
vector<int> g[MAXN];

int main(){
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
        }
        for (int i = 1; i <= n; i++) {
            sort(g[i].begin(), g[i].end());
            for (auto v : g[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
    return 0;
}