#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
int a[N], f[N];
int n, q;

int lowbit(int x) {
    return (x & (-x));
}

void add(int i, int k) {
    for ( ; i <= n; i += lowbit(i)) {
        f[i] += k;
    }
}

int query(int k) {
    int res = 0;
    for ( ; k; k -= lowbit(k)) {
        res += f[k];
    }
    return res;
}

int main(){
    cin >> n >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int a, b;
            cin >> a >> b;
            add(a, 1);
            add(b + 1, -1);
        }
        else {
            int a;
            cin >> a;
            cout << query(a) << endl;
        }
    }
    return 0;
}