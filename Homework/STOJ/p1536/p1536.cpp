#include <bits/stdc++.h>
using namespace std;

vector<int> fa;

int find(int a) {
    if (fa[a] == a) {
        return a;
    }
    return fa[a] = find(fa[a]);
}

void merge(int a, int b) {
    int x = find(a), y = find(b);
    if (x != y) {
        fa[x] = fa[y];
    }
}

int main(){
    while (1) {
        int m, n;
        cin >> n;
        if (n == 0)  return 0;
        cin >> m;
        if (m == 0){
            cout << n - 1 << endl;
            continue;
        }
        fa.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
        }
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            merge(u, v);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (fa[i] == i) {
                cnt++;
            }
        }
        cout << --cnt << endl;
        for (int i = 0; i < fa.size(); i++) {
            fa[i] = 0;
        }
    }
    return 0;
}