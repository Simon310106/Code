#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;

bool check(int v) {
    long long x, y, t;
    x = 1ll * a * v;
    y = 1ll * b * v;
    if (y > m) {
        t = (y - m + (b - a) - 1) / (b - a);
        y -= t * (b - a);
        x += t * (b - a);
    }
    return x <= n && y <= m;
}

int main(){
    cin >> n >> m >> a >> b;
    if (n > m) {
        swap(n, m);
    }
    if (a > b) {
        swap(a, b);
    }
    if (a == b) {
        cout << n / a << endl;
        return 0;
    }
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << r << endl;
    return 0;
}