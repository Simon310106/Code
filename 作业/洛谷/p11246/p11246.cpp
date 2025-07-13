#include <bits/stdc++.h>
using namespace std;

int n;
int dp[10005];

int main(){
    cin >> n;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        int tmp = i * i;
        for (int j = tmp; j <= n; j++) {
            dp[j] = min(dp[j], dp[j - tmp] + 1);
        }
    }
    return 0;
}