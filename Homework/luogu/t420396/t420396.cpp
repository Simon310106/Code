#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, dp[505];

signed main(){
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= i; j--) {
            dp[j] += dp[j - i];
        }
    }
    cout << dp[n] - 1 << endl;
    
    return 0;
}