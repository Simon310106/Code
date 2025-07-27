#include <bits/stdc++.h>
using namespace std;

string s, t;
int dp[5005][5005];

int main(){
    cin >> s;
    t = s;
    int n = s.size();
    reverse(t.begin(), t.end());
    s = '#' + s;
    t = '*' + t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i] == t[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << n - dp[n][n];
    return 0;
}