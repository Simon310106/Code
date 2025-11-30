#include <bits/stdc++.h>
using namespace std;

int t, m;
int w[105], v[105];
int dp[1005];

int main(){
    cin >> t >> m;
    for (int i = 1; i <= m; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = t; j >= 0; j--) {
            if (j >= w[i]) {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[t] << endl;
    return 0;
}