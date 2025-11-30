#include <bits/stdc++.h>
using namespace std;

int V, G, n;
int t[1005], v[1005], g[1005];
int dp[505][505];

int main(){
    cin >> V >> G >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> v[i] >> g[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = V; j >= v[i]; j--) {
            for (int k = G; k >= g[i]; k--) {
                dp[j][k] = max(dp[j][k], dp[j - v[i]][k - g[i]] + t[i]);
            }
        }
    }
    cout << dp[V][G] << endl;
    return 0;
}