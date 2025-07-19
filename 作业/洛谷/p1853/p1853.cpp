#include <bits/stdc++.h>
using namespace std;

int s, n, d;
int a[100005], b[100005], dp[100005];

int main(){
    cin >> s >> n >> d;
    for (int i = 1; i <= d; i++) {
        cin >> a[i] >> b[i];
        a[i] /= 1000;
    }
    memset(dp, 0, sizeof(dp));
    while (n--) {
        for (int i = 1; i <= d; i++) {
            for (int j = a[i]; j <= s / 1000; j++) {
                dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
            }
        }
        s += dp[s / 1000];
    }
    cout << s << endl;
    return 0;
}