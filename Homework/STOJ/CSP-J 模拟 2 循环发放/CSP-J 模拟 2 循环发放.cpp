#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, p;
int a[20005];

signed main(){
    cin >> n >> m >> p;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = p; i <= m; ) {
        ans += a[i];
        ans += a[i + (n - p) * 2];
        i += 2 * n;
    }
    cout << ans;
    return 0;
}