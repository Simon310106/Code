#include <bits/stdc++.h>
using namespace std;

int n, V;
int v[105], w[105], s[105];
int dp[1005];

int main(){
    cin >> n >> V;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i] >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] * v[i] >= V) {
            for (int j = v[i]; j <= V; j++) {
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
        else {
            for (int j = 1; j <= s[i]; j++) {
                for (int k = V; k >= v[i]; k--) {
                    dp[k] = max(dp[k], dp[k - v[i]] + w[i]);
                }
            }
        }
    }
    cout << dp[V] << endl;
    return 0;
}