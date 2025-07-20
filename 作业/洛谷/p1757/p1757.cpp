#include <bits/stdc++.h>
using namespace std;

int v, n, t;
int w[10005], z[10005], b[10005], dp[10005], g[205][205];

int main(){
    cin >> v >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> w[i] >> z[i] >> x;
        t = max(t, x);
        b[x]++;
        g[x][b[x]] = i; 
    }
    for (int i = 1; i <= t; i++) {
        for (int j = v; j >= 0; j--) {
            for (int k = 1; k <= b[i]; k++) {
                if (j >= w[g[i][k]]) {
                    dp[j] = max(dp[j], dp[j - w[g[i][k]]] + z[g[i][k]]);
                }
            }
        }
    }
    cout << dp[v] << endl;

    return 0;
}