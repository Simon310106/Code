#include <bits/stdc++.h>
using namespace std;

int v[50], w[50];
int dp[50010];

int main(){
    int n, m;
    cin >> m >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i] >> w[i];
        w[i] *= v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= v[i]; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[m];
    return 0;
}