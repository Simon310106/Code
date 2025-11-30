#include <bits/stdc++.h>
using namespace std;

int n, ans;
int a[1005], b[1005], c[1005];
int dp[1005][1005][3];

int main(){
    cin >> n;
    for  (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    } 
    // dp[0][0][0] = dp[0][0][1] = dp[0][0][2] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < 3; k++) {
                int add = 0, tmp = -2e9;
                if ((c[i] + 1) % 3 == k) add = (a[i] << 1);
                if (c[i] == k) add = a[i];
                if (j < i - 1 || i == 1) tmp = max(tmp, dp[i - 1][j][k]);
                if (j > 0) tmp = max(tmp, max(dp[i - 1][j - 1][(k + 1) % 3], dp[i - 1][j - 1][(k + 2) % 3]) - b[j]);
                dp[i][j][k] = tmp + add;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        ans = max({ans, dp[n][i][0], dp[n][i][1], dp[n][i][2]});
    }
    cout << ans;
    return 0;
}