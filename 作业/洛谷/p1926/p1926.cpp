#include <bits/stdc++.h>
using namespace std;

int n, m, k, r;
int t[50], w[50], v[50], dp[10005], sum, ans;

int main(){
    cin >> n >> m >> k >> r;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = r; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    for (int i = 0; i <= r; i++) {
        if (dp[i] >= k) {
            sum = r - i;
            break;
        }
    }
    sort(t + 1, t + n + 1);
    for (int i = 1; i <= n; i++) {
        if (sum >= t[i]) {
            ans++;
            sum -= t[i];
        }
    }
    cout << ans << endl;
    return 0;
}