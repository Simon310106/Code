#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N], f[N], ans[N];
int n;

int lowbit(int x) {
    return x & -x;
}

void add(int i, int k) {
    for ( ; i <= n; i += lowbit(i)) {
        f[i] += k;
    }
}

int query(int i) {
    int res = 0;
    for ( ; i; i -= lowbit(i)) {
        res += f[i];
    }
    return res;
}

int main(){
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        add(i, 1);
    }
    for (int i = n; i >= 1; i--) {
        int k = a[i] + 1;
        int l = -1, r = n + 1;
        while (l + 1 != r) {
            int mid = (l + r) >> 1;
            if (query(mid) < k) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        ans[i] = r;
        add(r, -1);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}