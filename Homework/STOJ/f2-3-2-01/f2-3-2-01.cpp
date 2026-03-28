#include <bits/stdc++.h>
using namespace std;

int n, m;
int wells[10005];
struct pipe{
    int u, v, w;
}pipes[20005];
int f[10005], cnt, res;

bool cmp(pipe a, pipe b) {
    return a.w < b.w;
}
int find(int a) {
    if (f[a] != a) {
        f[a] = find(f[a]);
    }
    return f[a];
}
void kruskal() {
    for (int i = 1; i <= m; i++) {
        int pa = find(pipes[i].u);
        int pb = find(pipes[i].v);
        if (pa != pb) {
            res += pipes[i].w;
            f[pa] = pb;
            cnt++;
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> wells[i];
        f[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> pipes[i].u >> pipes[i].v >> pipes[i].w;
    }
    for (int i = 1; i <= n; i++) {
        int idx = i + m;
        pipes[idx] = {0, i, wells[i]};
    }
    sort(pipes + 1, pipes + 1 + m, cmp);
    kruskal();
    sort(wells + 1, wells + 1 + n);
    cout << res + wells[1];
    return 0;
}