#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int p[105][1005];
int dp[105][1005];

int main(){
    cin >> t >> n >> m;
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j<= n; j++) {
            cin >> p[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[0][m] = 0;
    for (int i = 1; i <= t; i++) {
        for (int j = 0; j <= 1000; j++) {
            if (dp[i - 1][j] == -1) {
                continue;
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            for (int k = 1; k <= n; k++) {
                int ma = j / p[i][k];
                for (int l = 1; l <= ma; l++) {
                    int left = j - l * p[i][k];
                    dp[i][left] = max(dp[i][left], dp[i - 1][j] + l);
                }
                for (int l = 1; l <= (1000 - j) / p[i][0]; l++) {
                   int get = j + l * p[i][0];
                    if (get <= 1000) {
                        dp[i][get] = max(dp[i][get], dp[i - 1][j] + l);
                    }
                }
            }
            
        }
    }
    int ans = 0;
    for (int i = 0; i <= 1000; i++) {
        if (dp[t][i] != -1) {
            ans = max(ans, i);
        }
    }
    cout << ans;
    return 0;
}