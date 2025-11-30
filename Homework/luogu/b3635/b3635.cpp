#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;
int dp[MAXN];

int main(){
    int n;
    cin >> n;
    dp[0] = 0;
    for (int i = 1; i <= n; i++) dp[i] = 1e9;
    int coins[3] = {1, 5, 11};
    for (int i = 0; i < 3; i++) {
        for (int j = coins[i]; j <= n; j++) {
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }
    cout << dp[n] << endl;
    return 0;
}