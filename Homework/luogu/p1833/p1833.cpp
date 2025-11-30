#include <bits/stdc++.h>
using namespace std;

int st1, st2, ed1, ed2;
int T, n, N;
int t[100005], c[100005], p[100005];
int dp[1005];

signed main(){
    scanf("%d:%d %d:%d", &st1, &st2, &ed1, &ed2);
    T = (ed1 - st1) * 60 + (ed2 - st2);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int ti, ci, pi;
        cin >> ti >> ci >> pi;

        if (pi == 0) {
            for (int j = ti; j <= T; j++) {
                dp[j] = max(dp[j], dp[j - ti] + ci);
            }
        }
        else {
            int k = 1;
            while (pi >= k) {
                pi -= k;
                t[++n] = k * ti;
                c[n] = k * ci;
                k *= 2;
            }
            if (pi > 0) {
                t[++n] = pi * ti;
                c[n] = pi * ci;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = T; j >= t[i]; j--) {
            dp[j] = max(dp[j], dp[j - t[i]] + c[i]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= T; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;

    return 0;
}