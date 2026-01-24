#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k, sum;
int a[505], c[505], dp[1000005];

signed main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        sum += a[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= a[i]; j--) {
            dp[j] = min(dp[j], dp[j - a[i]] + c[i]);
        }
    }
    for (int i = sum; i >= 0; i--) {
        if (dp[i] <= k) {
            cout << i << endl;;
            break;
        }
    }
    return 0;
}