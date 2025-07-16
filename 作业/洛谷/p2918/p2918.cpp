#include <bits/stdc++.h>
using namespace std;

int n, h;
int p[110], c[110], dp[100005];

int main(){
    cin >> n >> h;
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> c[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = h; j >= p[i]; j--) {
            dp[j] = max(dp[j], dp[j - p[i]] + c[i]);
        }
    }
    cout << dp[h] << endl;
    return 0;
}