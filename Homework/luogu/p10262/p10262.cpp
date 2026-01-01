#include <bits/stdc++.h>
using namespace std;

int p;
long long dp[200], pre[200], ans;
string s;

int main(){
    cin >> p >> s;
    long long L = s.length();
    for (int i = 0; i < L; i++) {
        long long tmp = (s[i] - '0') % p;
        memset(dp, 0, sizeof(dp));
        for (int j = 0; j < p; j++) {
            dp[(j * 10 + tmp) % p] += pre[j];
        }
        dp[tmp]++;
        for (int j = 0; j < p; j++) {
            pre[j] = dp[j];
        }
        ans += dp[0];
    }
    cout << ans;
    return 0;
}