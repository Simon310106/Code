#include <bits/stdc++.h>
using namespace std;

int g[105][105], must[10005];

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> must[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (g[i][k] + g[k][j] < g[i][j]) {
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 2; i <= m; i++) {
        ans += g[must[i - 1]][must[i]];
    }
    cout << ans;
    return 0;
}