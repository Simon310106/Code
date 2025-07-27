#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, a[1005][1005], dp[1005][1005][2];

signed main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            dp[i][j][0] = dp[i][j][1] = INT_MIN;
        }
    }
    dp[1][1][0] = dp[1][1][1] = a[1][1];
    for (int i = 2; i <= n; i++) {
        dp[i][1][0] = dp[i - 1][1][0] + a[i][1];
    }
    for (int i = 2; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[j][i][0] = dp[j][i][1] = max(dp[j][i - 1][1], dp[j][i - 1][0]) + a[j][i];
        }
        for (int j = 2; j <= n; j++) {
            dp[j][i][0] = max(dp[j][i][0], dp[j - 1][i][0] + a[j][i]);
        }
        for (int j = n - 1; j >= 1; j--) {
            dp[j][i][1] = max(dp[j][i][1], dp[j + 1][i][1] + a[j][i]);
        }
    }
    cout << max(dp[n][m][0], dp[n][m][1]) << endl;
    return 0;
}