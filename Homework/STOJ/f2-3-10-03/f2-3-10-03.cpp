#include <bits/stdc++.h>
using namespace std;

const int N = 205;
int a[N][N], f[N][N], m, n;

int lowbit(int x) {
    return (x & (-x));
}

void add(int x, int y, int k) {
    for (int i = x ; i <= m; i += lowbit(i)) {
        for (int j = y ; j <= n; j += lowbit(j)) {
            f[i][j] += k;
        }
    }
}

int query(int x, int y) {
    int res = 0;
    for (int i = x ; i; i -= lowbit(i)) {
        for (int j = y ; j; j -= lowbit(j)) {
            res += f[i][j];
        }
    }
    return res;
}

int query(int x1, int y1, int x2, int y2) {
    return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
}

int main(){
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            add(i, j, a[i][j]);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int opr;
        cin >> opr;
        if (opr == 1) {
            int row, col, val;
            cin >> row >> col >> val;
            row++, col++;
            int delta = val - a[row][col];
            a[row][col] = val;
            add(row, col, delta);
        }
        else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1++, y1++, x2++, y2++;
            cout << query(x1, y1, x2, y2) << endl;
        }
    }
    return 0;
}