#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2005;
int n, a[N], dp[N], cnt[N];

signed main(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = 1;
        cnt[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (a[j] < a[i]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                }
                else if (dp[j] + 1 == dp[i]) {
                    cnt[i] += cnt[j];
                }
            }
        }
    }
    int ma = -1;
    for (int i = 1; i <= n; i++) {
        ma = max(ma, dp[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] == ma) {
            ans += cnt[i];
        }
    }
    cout << ans << endl;
    return 0;
}