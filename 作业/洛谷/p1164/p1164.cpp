#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[105], dp[10005];

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= a[i]; j--) {
            dp[j] += dp[j - a[i]];
        }
    }
    cout << dp[m] << endl;
    return 0;
}