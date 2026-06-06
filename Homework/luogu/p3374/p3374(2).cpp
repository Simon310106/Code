#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int a[N], s[4 * N];

// 上传
void pushup(int i) {
    s[i] = s[i << 1] + s[(i << 1) + 1];
}
// 建树
void build(int i, int l, int r) {
    if (l == r) {
        s[i] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(i << 1, l, mid);
    build((i << 1) + 1, mid + 1, r);
    // 回溯
    pushup(i);
}
void update(int i, int l, int r, int x, int k) {
    if (l == r) {
        s[i] += k;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) {
        update(i << 1, l, mid, x, k);
    }
    else {
        update((i << 1) + 1, mid + 1, r, x, k);
    }
    pushup(i);
}
int query(int i, int l, int r, int ql, int qr) {
    // 查询区间完全越界
    if (qr < l || ql > r) return 0;
    // 查询区间完全包含任务区间
    if (ql <= l && r <= qr) return s[i];
    int mid = (l + r) >> 1;
    int L = query(i << 1, l, mid, ql, qr);
    int R = query((i << 1) + 1, mid + 1, r, ql, qr);
    return L + R;
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while(m--) {
        int opr, x, y, k;
        cin >> opr;
        if (opr == 1) {
            cin >> x >> k;
            update(1, 1, n, x, k);
        }
        else {
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << endl;
        }
    }
    return 0;
}