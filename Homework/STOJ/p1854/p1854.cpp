#include <bits/stdc++.h>
using namespace std;

int n;
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
    cin >> n;
    int idx = 0;
    fa.resize(n + 5);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w;
            cin >> w;
            if (j < i) {
                idx++;
                edge[idx] = {i, j, w};
            }
        }
    }
    int ans = 0;
    sort(edge + 1, edge + 1 + idx, cmp);
    for (int i = 1; i <= idx; i++) {
        int x = edge[i].u, y = edge[i].v;
        if (find(x) == find(y)) {
            continue;
        }
        merge(x, y);
        ans += edge[i].w;
    }
    cout << ans;
    return 0;
}