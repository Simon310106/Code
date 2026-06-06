#include <bits/stdc++.h>
using namespace std;

const int  N = 1e6 + 5;
int a[N], f[N], n, m, vis[N], ans[N];

struct node {
    int l, r, id;
}q[N];

bool cmp(node a, node b) {
    return a.r < b.r;
}

int lowbit(int x) {
    return (x & (-x));
}

void add(int pos, int val) {
    for (int i = pos; i <= n; i += lowbit(i)) {
        f[i] += val;
    }
}

int query(int pos) {
    int res = 0;
    for (int i = pos; i; i -= lowbit(i)) {
        res += f[i];
    }
    return res;
}

int query(int L, int R) {
    return query(R) - query(L - 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(), cout.tie();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + m + 1, cmp);
    for (int s = 1, i = 1; i <= m; i++) {
        while (s <= q[i].r) {
            if (vis[a[s]] != 0) {
                add(vis[a[s]], -1);
            }
            add(s, 1);
            vis[a[s]] = s;
            s++;
        }
        ans[q[i].id] = query(q[i].l, q[i].r);
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}