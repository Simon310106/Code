#include <bits/stdc++.h>
#define INT_MAX 0x3f3f3f3f
using namespace std;

int c[100005], l[100005], sum, dp[100005], ans = INT_MAX - 1;

int main(){
    int n, s;
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> l[i];
        l[i] = min(l[i], s), sum += l[i];
    }
    if (sum < s) {
        cout << "no solution" << endl;
        return 0;
    }
    for (int i = 1; i <= 2 * s; i++) {
        dp[i] = INT_MAX - 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 2 * s; j >= l[i]; j--) {
            dp[j] = min(dp[j], dp[j - l[i]] + c[i]);
        }
    }
    for (int i = s; i <= 2 * s; i++) {
        ans = min(ans, dp[i]);
    }

    if (ans == INT_MAX - 1) {
        cout << "no solution" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}