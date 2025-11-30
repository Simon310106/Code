#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, a[205];
int dp[1005][1005];

signed main(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int len = 3; len <= n + 1; len++) {
        for (int i = 1; i + len - 1 <= 2 * n; i++) {
            int r = i + len - 1;
            for (int k = i + 1; k < r; k++) {
                dp[i][r] = max(dp[i][r], dp[i][k] + dp[k][r] + a[i] * a[k] * a[r]);
            }
        }
    }
    int ans = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i][i + n]);
    }
    cout << ans << endl;

    return 0;
}