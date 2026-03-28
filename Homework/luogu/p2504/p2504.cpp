#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005, MAXM = 505, MAXK = MAXN * (MAXN - 1) / 2 + 10; 
int n, m, k;
int jump[MAXM];
struct node{
    int a, b;
    double w;
}edge[MAXK];
int px[MAXN], py[MAXN], f[MAXN];
int res, cnt;
double ma = INT_MIN;

bool cmp(node a, node b) {
    return a.w < b.w;
}
int find(int a) {
    if (f[a] == a) {
        return a;
    }
    return f[a] = find(f[a]);
}
void kruakal() {
    for (int i = 1; i <= k; i++) {
        int pa = find(edge[i].a);
        int pb = find(edge[i].b);
        if (pa != pb) {
            res += edge[i].w;
            f[pa] = pb;
            cnt++;
            ma = max(ma, edge[i].w);
            if (cnt == n - 1) break;
        }
    }
}

int main(){
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> jump[i];
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> px[i] >> py[i];
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            k++;
            double dis = sqrt((px[i] - px[j]) * (px[i] - px[j]) 
                         + (py[i] - py[j]) * (py[i] - py[j]));
            edge[k] = {i, j, dis};
        }
    }
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    sort(edge + 1, edge + 1 + k, cmp);
    kruakal();
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        if (jump[i] >= ma) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
// 距离：sqrt(x1 * x2 + y1 * y2)