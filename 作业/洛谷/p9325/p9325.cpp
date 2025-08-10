#include <bits/stdc++.h>
using namespace std;

int n, h[5005], dp[5005][5005], mi[5005];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int len = 2; len <= n; len++) {
        mi[len] = 0x3f3f3f3f;
        for (int i = 1; i + len - 1 <= n; i++) {
            int r = i + len - 1;
            dp[i][r] = dp[i + 1][r - 1] + abs(h[i] - h[r]);
            mi[len] = min(mi[len], dp[i][r]);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << mi[i] << " ";
    }
    return 0;
}