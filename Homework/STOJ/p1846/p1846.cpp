#include <bits/stdc++.h>
using namespace std;

vector<int> fa, dep;
int find(int a) {               // 查找
    if (fa[a] == a) {
        return a;
    }
    return fa[a] = find(fa[a]); // 路径压缩
}

void Union(int a, int b) {      // 合并
    int x = find(a), y = find(b);
    if (dep[x] < dep[y]) {
        fa[x] = y;
    }
    else {
        fa[y] = x;
    }
    if (dep[x] == dep[y] && x != y) {
        dep[x]++;
    }
}

int main(){
    int n, m, p;
    cin >> n >> m >> p;
    fa.resize(n + 1);
    dep.resize(n + 1);
    // 初始化
    for (int i = 0; i < n; i++) {
        fa[i] = i;
        dep[i] = 1;
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }
    while (p--) {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}