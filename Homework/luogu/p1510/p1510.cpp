#include <bits/stdc++.h>
using namespace std;

int v, n, c;
int val[10005], wt[10005], dp[10005];

int main(){
    cin >> v >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> val[i] >> wt[i];
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = c; j >= wt[i]; j--) {
            if (dp[j - wt[i]] != -1) {
                dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
            }
        }
    }
    int ans = -1;
    for (int i = 1; i <= c; i++) {
        if (dp[i] >= v) {
            ans = i;
            break;
        }
    }
    if (ans == -1) {
        cout << "Impossible" << endl;
    } else {
        cout << c - ans << endl;
    }
    return 0;
}