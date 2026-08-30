#include <bits/stdc++.h>
#define int long long
using namespace std;

int l[20005], r[20005];
int dp[20005][2];

signed main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    dp[1][0] = abs(1 - r[1]) + (r[1] - l[1]);
    dp[1][1] = abs(1 - l[1]) + (r[1] - l[1]);
    for (int i = 2; i <= n; i++) {
        int len = r[i] - l[i];
        dp[i][0] = min(
            dp[i - 1][0] + abs(l[i - 1] - r[i]) + 1 + len,
            dp[i - 1][1] + abs(r[i - 1] - r[i]) + 1 + len
        );
        dp[i][1] = min(
            dp[i - 1][0] + abs(l[i - 1] - l[i]) + 1 + len,
            dp[i - 1][1] + abs(r[i - 1] - l[i]) + 1 + len
        );
    }
    cout << min(
        dp[n][0] + abs(n - l[n]),
        dp[n][1] + abs(n - r[n])
    ) << endl;
    return 0;
}