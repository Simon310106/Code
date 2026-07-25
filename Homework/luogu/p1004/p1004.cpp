#include <bits/stdc++.h>
using namespace std;

int g[10][10];
int dp[10][10][10][10];

int main(){
    int n;
    cin >> n;
    int x = 1, y = 1, v = 1;
    while (cin >> x >> y >> v) {
        if (x == 0 && y == 0 && v == 0) break;
        g[x][y] = v;
    }
    dp[1][1][1][1] = g[1][1];
    for (int a = 1; a <= 9; a++) {
        for (int b = 1; b <= 9; b++) {
            for (int c = 1; c <= 9; c++) {
                for (int d = 1; d <= 9; d++) {
                    dp[a][b][c][d] = max({dp[a-1][b][c-1][d],
                                          dp[a-1][b][c][d-1],
                                          dp[a][b-1][c-1][d],
                                          dp[a][b-1][c][d-1]})
                                     + (a == c && b == d ? g[a][b] : g[a][b] + g[c][d]);
                }
            }
        }
    }
    cout << dp[n][n][n][n] << endl;
    return 0;
}