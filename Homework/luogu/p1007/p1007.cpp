#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[105];
int dp[105][105];
const int mod = 1e6 + 7;

signed main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= min(j, a[i]); k++) {
                dp[i][j] += dp[i - 1][j - k] % mod;
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}