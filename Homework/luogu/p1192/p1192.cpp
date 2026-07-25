#include <bits/stdc++.h>
using namespace std;

const int MOD = 100003;
int n, k;
int dp[100005];

int main(){
    cin >> n >> k;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] += dp[i - 1];
        dp[i] %= MOD;
        for (int j = 2; j <= min(k, i); j++) {
            dp[i] += dp[i - j];
            dp[i] %= MOD;
        }
    }
    cout << dp[n] % MOD;
    return 0;
}