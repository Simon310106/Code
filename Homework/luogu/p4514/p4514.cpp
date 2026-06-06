#include <bits/stdc++.h>
using namespace std;

const int N = 2050;
int n, m, a[N][N], f1[N][N], f2[N][N], f3[N][N], f4[N][N];

int lowbit(int x) {
    return (x & (-x));
}

void add(int x, int y, int k) {
    int k1 = k, k2 = k * x, k3 = k * y, k4 = k * x * y;
    for (int i = x ; i <= n; i += lowbit(i)) {
        for (int j = y; j <= m; j += lowbit(j)) { 
            f1[i][j] += k1;
            f2[i][j] += k2;
            f3[i][j] += k3;
            f4[i][j] += k4;
        }
    }
}

int query(int x, int y) {
    int res = 0;
    for (int i = x ; i; i -= lowbit(i)) {
        for (int j = y; j; j -= lowbit(j)) {  
            res += (x + 1) * (y + 1) * f1[i][j]
                 - (y + 1) * f2[i][j]
                 - (x + 1) * f3[i][j]
                 + f4[i][j];
        }
    }
    return res;
}


int query(int x1, int y1, int x2, int y2) {
    return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
}

int main(){
    char c;
    cin >> c >> n >> m;
    while (cin >> c) {
        if (c == 'L') {
            int a, b, c, d, delta;
            cin >> a >> b >> c >> d >> delta;
            add(a, b, delta);
            add(a, d + 1, -delta);
            add(c + 1, b, -delta);
            add(c + 1, d + 1, delta);
        }
        else {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            cout << query(a, b, c, d) << endl;
        }
    }
    return 0;
}