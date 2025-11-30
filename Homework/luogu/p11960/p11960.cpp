#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10;
int a[N], b[N], ans, c;

bool cmp (int x, int y) {
    return x > y;
}

signed main(){
    int n;
    cin >> n;
    for (int i = 1; i <= 2 * n; i++){
        cin >> b[i];
        ans += b[i];
    }
    for (int i = 1; i <= 2 * n; i++) {
        cin >> c;
        a[i] = c - b[i];
    }
    sort(a + 1, a + 2 * n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}