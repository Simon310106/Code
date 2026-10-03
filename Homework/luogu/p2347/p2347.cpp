#include <bits/stdc++.h>
using namespace std;

int dp[3000], a[3000];
int nums[10] = {0, 1, 2, 3, 5, 10, 20};
int ans;

int main(){
    int n = 0, sum = 0;
    for (int i = 1; i <= 6; i++) {
        int k;
        cin >> k;
        sum += k * nums[i];
        for (int j = 1; j <= k; j++) {
            a[++n] = nums[i];
        }
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= a[i]; j--) {
            dp[j] += dp[j - a[i]];
        }
    }
    for (int i = 1; i <= sum; i++) {
        if (dp[i]) {
            ans++;
        }
    }
    cout << "Total=" << ans << endl;
    return 0;
}