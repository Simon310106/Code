#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int f[N];
int n, m, res, cnt;

struct node {
    int a, b, w;
}edge[2 * N];

bool cmp(node a, node b) {
    return a.w < b.w;
}
int find(int a) {
    if(f[a] != a) f[a] = find(f[a]);
    return f[a];
}

void kruakal() {
    for (int i = 1; i <= m; i++) {
        int pa = find(edge[i].a);
        int pb = find(edge[i].b);
        if (pa != pb) {
            res += edge[i].w;
            f[pa] = pb;
            cnt++;
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> edge[i].a >> edge[i].b >> edge[i].w;
    }
    sort(edge + 1, edge + 1 + m, cmp);
    kruakal();
    if (cnt < n - 1) {
        cout << "orz" << endl;
    }
    else {
        cout << res << endl;
    }
    return 0;
}