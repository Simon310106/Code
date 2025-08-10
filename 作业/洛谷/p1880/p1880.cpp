#include <bits/stdc++.h>
using namespace std;

int n, a[1005], dp[1005][1005], f[1005][1005];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= 2 * n; i++) {
        a[i] += a[i - 1];
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= 2 * n; i++) {
            int j = i + len - 1;
            dp[i][j] = 0x3f3f3f3f;
            f[i][j] = -0x3f3f3f3f;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + a[j] - a[i - 1]);
                f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + a[j] - a[i - 1]);
            }
        }
    }
    int mi = 0x3f3f3f3f, ma = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        mi = min(mi, dp[i][i + n - 1]);
        ma = max(ma, f[i][i + n - 1]);
    }
    cout << mi << "\n" << ma << endl;
    return 0;
}