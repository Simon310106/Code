#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, dp[1005];
int pri[1005], vis[1005], cnt;

void prime(int n) {
    memset(vis, 0, sizeof(vis));
    cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (!vis[i])
            pri[cnt++] = i;
        for (int j = 0; j < cnt && i * pri[j] <= n; j++) {
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
}

signed main(){
    cin >> n;
    prime(n);
    dp[0] = 1;
    for (int i = 0; i < cnt; i++) {
        for (int j = pri[i]; j <= n; j++) {
            dp[j] += dp[j - pri[i]];
        }
    }
    cout << dp[n] << endl;
    return 0;
}