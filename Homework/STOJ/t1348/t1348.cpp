#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

int n, e;
struct node{
    int a, b, w;
}edge[10005];
int f[10005];
pair<int, int> pos[10005];
int cnt;
int idx = 0;

bool cmp(node a, node b) {
    return a.w < b.w;
}
bool cmp1(pair<int, int> a, pair<int, int> b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
int find(int a) {
    if (f[a] != a) {
        f[a] = find(f[a]);
    }
    return f[a];
}
void kruskal() {
    for (int i = 1; i <= e; i++) {
        int pa = find(edge[i].a);
        int pb = find(edge[i].b);
        if (pa != pb) {
            pos[++idx].x = min(edge[i].a, edge[i].b);
            pos[idx].y = max(edge[i].a, edge[i].b);
            f[pa] = pb;
            cnt++;
        }
    }
}

int main(){
    cin >> n >> e;
    for (int i = 1; i <= e; i++) {
        cin >> edge[i].a >> edge[i].b >> edge[i].w;
    }
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    sort(edge + 1, edge + 1 + e, cmp);
    kruskal();
    sort(pos + 1, pos + 1 + idx, cmp1);
    for (int i = 1; i <= idx; i++) {
        cout << pos[i].x << " " << pos[i].y << endl;
    }
    return 0;
}