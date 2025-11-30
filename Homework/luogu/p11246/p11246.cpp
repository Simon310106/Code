#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1000005];

int main(){
    cin >> n;
    memset(dp, 0x3f, sizeof(dp));   
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = i * i;
        if (tmp > n) {
            break;
        }
        for (int j = tmp; j <= n; j++) {
            dp[j] = min(dp[j], dp[j - tmp] + 1);
        }
    }
    cout << dp[n] << endl;
    return 0;
}