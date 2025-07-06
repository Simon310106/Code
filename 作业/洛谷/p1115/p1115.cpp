#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 20;

int n, ans;
int a[N];
int dp[N];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[1] = a[1];
    ans = a[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = max(a[i], dp[i - 1] + a[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}