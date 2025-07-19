#include <bits/stdc++.h>
using namespace std;

int n, h;
int p[110], c[110], dp[100005];

int main(){
    cin >> n >> h;
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> c[i];
    }
    const int INF = 1e9;
    for (int i = 1; i <= 100000; i++) dp[i] = INF;
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = p[i]; j <= 100000; j++) {
            dp[j] = min(dp[j], dp[j - p[i]] + c[i]);
        }
    }
    int ans = INF;
    for (int i = h; i <= 100000; i++) {
        ans = min(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}