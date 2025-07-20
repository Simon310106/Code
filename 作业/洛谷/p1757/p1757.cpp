#include <bits/stdc++.h>
using namespace std;

int n, m, t;
int w[1005], v[1005], cnt[1005], dp[10005], g[1005][1005];

int main(){
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> w[i] >> v[i] >> x;
        t = max(t, x);
        cnt[x]++;
        g[x][cnt[x]] = i; 
    }
    for (int i = 1; i <= t; i++) {
        for (int j = m; j >= 0; j--) {
            for (int k = 1; k <= cnt[i]; k++) {
                if (j >= w[g[i][k]]) {
                    dp[j] = max(dp[j], dp[j - w[g[i][k]]] + v[g[i][k]]);
                }
            }
        }
    }
    cout << dp[m] << endl;

    return 0;
}