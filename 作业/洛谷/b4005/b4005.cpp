#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, a[15][15], ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char t;
            cin >> t;
            a[i][j] = t - '0';
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = i; k <= n; k++) {
                for (int l = j; l <= m; l++) {
                    int sum = 0;
                    for (int x = i; x <= k; x++) {
                        for (int y = j; y <= l; y++) {
                            sum += a[x][y];
                        }
                    }
                    if (sum * 2 == (k - i + 1) * (l - j + 1)) {
                        ans = max(ans, (k - i + 1) * (l - j + 1));
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}