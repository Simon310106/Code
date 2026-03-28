#include <bits/stdc++.h>
using namespace std;

int m, n;
int f[2000005];
int ans;
int find(int a) {
    if (f[a] != a) {
        f[a] = find(f[a]);
    }
    return f[a];
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> m >> n;
    for (int i = 1; i <= n * m; i++) {
        f[i] = i;
    }
    int x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        int u = n * (x1 - 1) + y1, v = n * (x2 - 1) + y2;
        int pa = find(u);
        int pb = find(v);
        if (pa != pb) f[pa] = pb;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            int a = n * (i - 1) + j;
            int b = n * i + j;
            int pa = find(a), pb = find(b);
            if (pa != pb) {
                f[pa] = pb;
                ans += 1;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j < n; j++) {
            int a = n * (i - 1) + j;
            int b = n * (i - 1) + j + 1;
            int pa = find(a), pb = find(b);
            if (pa != pb) {
                f[pa] = pb;
                ans += 2;
            }
        }
    }
    cout << ans;
    return 0;
}
// id = n * (i - 1) + j;