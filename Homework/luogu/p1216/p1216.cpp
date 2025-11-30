#include <bits/stdc++.h>
using namespace std;

int a[1005][1005], dp[1005][1005];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;

    return 0;
}