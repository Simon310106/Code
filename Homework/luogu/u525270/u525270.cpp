#include <bits/stdc++.h>
#define int long long 
using namespace std;

int n, a[100005], b[100005], dp[100005][3];

signed main(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    dp[1][1] = a[1];
    dp[1][2] = b[1];
    dp[2][1] = max(dp[1][1] + a[2], b[1]);
    dp[2][2] = max(dp[1][2] + b[2], a[1]);
    for (int i = 3; i <= n; i++) {
        dp[i][1] = max(dp[i - 1][1], dp[i - 2][2]) + a[i];
        dp[i][2] = max(dp[i - 1][2], dp[i - 2][1]) + b[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(dp[i][1], ans);
        ans = max(dp[i][2], ans);
    }
    cout << ans;
    return 0;
}
