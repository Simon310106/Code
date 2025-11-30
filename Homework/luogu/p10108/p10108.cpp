#include <bits/stdc++.h>
using namespace std;

int n, m, a[105], b[20005], dp[20005];

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    memset(dp, -0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < m; j++) {
            if (i >= a[j]) {
                dp[i] = max(dp[i], dp[i - a[j]] + b[i - a[j]]);
            }
        }
    }
    int ans = -0x3f3f3f3f;
    for (int i = n; i < 2 * n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}