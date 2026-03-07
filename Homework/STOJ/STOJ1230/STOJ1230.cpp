#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> fa;
int find(int a) {
    if (fa[a] == a) {
        return a;
    }
    return fa[a] = find(fa[a]);
}
void Union(int a, int b) {
    if (find(a) != find(b)) {
        fa[find(b)] = find(a);
    }
}

signed main(){
    int n, m;
    cin >> n >> m;
    fa.resize(n * n + n + 1);
    for (int i = 0; i <= n * n + n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        int a, b;
        a = (x - 1) * n + y;
        if (c == 'D') {
            b = x * n + y;
        }
        if (c == 'R') {
            b = (x - 1) * n + y + 1;
        }
        // cout << a << " " << b << " " << find(a) << " " << find(b) << endl;
        if (find(a) == find(b)) {
            cout << i << endl;
            return 0;
        }
        Union(a, b);
    }
    cout << "draw" << endl;
    return 0;
}