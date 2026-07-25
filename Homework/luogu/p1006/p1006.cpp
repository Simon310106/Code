#include <bits/stdc++.h>
using namespace std;

int g[60][60];
int dp[60][60][60][60];

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= m; b++) {
            for (int c = 1; c <= n; c++) {
                for (int d = 1; d <= m; d++) {
                    dp[a][b][c][d] = max({dp[a-1][b][c-1][d],
                                          dp[a-1][b][c][d-1],
                                          dp[a][b-1][c-1][d],
                                          dp[a][b-1][c][d-1]})
                                     + (a == c && b == d ? g[a][b] : g[a][b] + g[c][d]);
                }
            }
        }
    }
    cout << dp[n][m][n][m] << endl;
    return 0;
}