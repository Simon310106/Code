#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[100005], b[100005];
int ans, dp[200005];

signed main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = n; i >= 1; i--) {
        dp[i] = max(dp[i + 1], dp[max(1ll, b[i]) + i] + a[i]);
    }
    cout << dp[1];

    return 0;
}