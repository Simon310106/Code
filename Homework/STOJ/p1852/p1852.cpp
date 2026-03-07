#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> fa;
bool vis[100005];

struct node{
    int u, v, w;
}edge[100005];

int find(int a) {
    if (fa[a] == a) {
        return a;
    }
    return fa[a] = find(fa[a]);
}

void merge(int a, int b) {
    int x = find(a), y = find(b);
    if (x != y) {
        fa[x] = y;
    }
}

bool cmp(node a, node b) {
    return a.w < b.w;
}

int main(){
    cin >> n >> m;
    int idx = 0;
    fa.resize(n + 5);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[++idx] = {u, v, w};
    }
    int ans = -1, cnt = 0;
    sort(edge + 1, edge + 1 + idx, cmp);
    for (int i = 1; i <= idx; i++) {
        int x = edge[i].u, y = edge[i].v;
        if (find(x) == find(y)) {
            continue;
        }
        merge(x, y);
        ans = edge[i].w;
        if (cnt == n - 1) {
            break;
        }
    }
    int tmp = 0;
    for (int i = 1; i <= n; i++) {
        if (fa[i] == i)
            tmp++;
    }
    if (tmp != 1)   cout << -1;
    else cout << ans;
    return 0;
}