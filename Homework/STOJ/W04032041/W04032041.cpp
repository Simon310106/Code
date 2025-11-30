#include <bits/stdc++.h>
using namespace std;

int n, m;

struct node {
    int v, w;
};

vector<node> e[1000005];

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    for (int i = 0; i < n; i++) {
        cout << i << ":";
        for (int j = e[i].size() - 1; j >= 0; j--) {
            cout << "[" << e[i][j].v << "," << e[i][j].w << "]";
        }
        cout << endl;
    }
    return 0;
}