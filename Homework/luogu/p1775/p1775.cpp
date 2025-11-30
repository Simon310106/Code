#include <bits/stdc++.h>
using namespace std;

int n, a[1005], dp[1005][1005];

int main(){
    memset(dp, 0x3f, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
        dp[i][i] = 0; 
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + a[j] - a[i - 1]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}