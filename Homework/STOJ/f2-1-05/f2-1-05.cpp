#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
int dp[5005][5005];
const int mod = 1000000007;

signed main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        dp[i][1] = m;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j] * j) % mod;
            dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * (m - (j - 1))) % mod;
        }
    }
    cout << dp[n][m];
    return 0;
}