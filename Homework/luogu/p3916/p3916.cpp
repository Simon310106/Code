#include <bits/stdc++.h>
using namespace std;

int n, m;
int b[100005];
vector<int> a[100005];

void dfs (int x, int d) {
    if (b[x]) {
        return;
    }
    b[x] = d;
    for (int i = 0; i < a[x].size(); i++) {
        dfs(a[x][i], d);
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[v].push_back(u);
    }
    for (int i = n; i >= 1; i--) {
        dfs(i, i);
    }
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    return 0;
}