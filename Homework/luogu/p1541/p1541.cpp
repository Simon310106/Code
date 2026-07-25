#include <bits/stdc++.h>
using namespace std;

int dp[45][45][45][45];
int n, m, score[355], num[125];
int cnt1, cnt2, cnt3, cnt4;

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> score[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> num[i];
        if (num[i] == 1)       cnt1++;
        else if (num[i] == 2)  cnt2++;
        else if (num[i] == 3)  cnt3++;
        else if (num[i] == 4)  cnt4++;
    }
    dp[0][0][0][0] = num[1];
    for (int a = 0; a <= cnt1; a++) {
        for (int b = 0; b <= cnt2; b++) {
            for (int c = 0; c <= cnt3; c++) {
                for (int d = 0; d <= cnt4; d++) {
                    int res = 1 + a * 1 + b * 2 + c * 3 + d * 4;
                    int p1 = (a == 0 ? 0 : dp[a - 1][b][c][d]), 
                        p2 = (b == 0 ? 0 : dp[a][b - 1][c][d]),
                        p3 = (c == 0 ? 0 : dp[a][b][c - 1][d]), 
                        p4 = (d == 0 ? 0 : dp[a][b][c][d - 1]);
                    dp[a][b][c][d] = max({p1, p2, p3, p4}) + score[res];
                }
            }
        }
    }
    cout << dp[cnt1][cnt2][cnt3][cnt4] << endl;
    return 0;
}