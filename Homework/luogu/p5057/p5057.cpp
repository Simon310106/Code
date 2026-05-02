#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], f[N];
int n, q;

int lowbit(int x) {
    return (x & (-x));
}

void add(int i) {
    for ( ; i <= n; i += lowbit(i)) {
        f[i]++;
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
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            add(l);
            add(r + 1);
        }
        else {
            int i;
            cin >> i;
            cout << query(i) % 2 << endl;
        }
    }
    return 0;
}