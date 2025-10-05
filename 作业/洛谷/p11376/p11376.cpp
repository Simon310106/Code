#include <bits/stdc++.h>
using namespace std;

int n, m, s;
int cf, cg;

struct node1 {
    int p, c;
}e[100005];

struct node2 {
    int a, b;
}g[100005], f[100005];

bool cmp1(node1 x, node1 y) {
    return x.p < y.p;
}

bool cmp2(node2 x, node2 y) {
    return x.a - x.b > y.a - y.b;
}

bool cmp3(node2 x, node2 y) {
    return x.b - x.a > y.b - y.a;
}

int main(){
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) {
        cin >> e[i].p >> e[i].c;
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        if (x >= y) {
            f[++cf] = {x, y};
        }
        else {
            g[++cg] = {x, y};
        }
    }
    sort (e + 1, e + n + 1, cmp1);
    sort (f + 1, f + cf + 1, cmp2);
    sort (g + 1, g + cg + 1, cmp3);
    int now = 1;
    long long ans = 0;
    for (int i = 1; i <= cf; i++) {
        if (e[now].c == 0) now++;
        ans += 2ll * f[i].a * e[now].p + 2ll * f[i].b * (s - e[now].p);
        e[now].c--;
    }
    now = n;
    for (int i = 1; i <= cg; i++) {
        if (e[now].c == 0) now--;
        ans += 2ll * g[i].a * e[now].p + 2ll * g[i].b * (s - e[now].p);
        e[now].c--;
    }
    cout << ans << endl;

    return 0;
}