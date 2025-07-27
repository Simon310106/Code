#include <bits/stdc++.h>
using namespace std;

int n, m, dp[10005];

struct node{
    int t, x, y;
}a[10005];

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        dp[i] = 1;
        cin >> a[i].t >> a[i].x >> a[i].y;
    }
    for (int i = m; i >= 1; i--) {
        for (int j = i - 1; j >= 1; j--) {
            if (a[i].t - a[j].t >= abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y)) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}