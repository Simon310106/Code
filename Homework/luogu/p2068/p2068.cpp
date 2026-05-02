#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int a[N], f[N];
int n, w;

int lowbit(int x) {
    return (x & (-x));
}

void add(int pos, int val) {
    for ( ; pos <= n; pos += lowbit(pos)) {
        f[pos] += val;
    }
}

int query(int pos) {
    int res = 0;
    for ( ; pos; pos -= lowbit(pos)) {
        res += f[pos];
    }
    return res;
}

int query(int L, int R) {
    return query(R) - query(L - 1);
}

signed main(){
    cin >> n >> w;
    while (w--) {
        char t;
        int a, b;
        cin >> t >> a >> b;
        if (t == 'x') {
            add(a, b);
        }
        else {
            cout << query(a, b) << endl;;
        }
    }
    return 0;
}