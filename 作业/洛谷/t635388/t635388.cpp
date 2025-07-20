#include <bits/stdc++.h>
using namespace std;

int n;
int v[1005], w[1005], dp[1005];

int main(){
    cin >> n;
    for (int i = 1; i <= 3; i++) {
        cin >> v[i] >> w[i];
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= 3; i++) {
        int tmp = (n + v[i] - 1) / v[i];
        ans = min(ans, tmp * w[i]);
    }
    cout << ans;
    return 0;
}