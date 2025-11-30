#include <bits/stdc++.h>
using namespace std;

int a[105][105], sum[105][105];

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }
    int mi = INT_MAX;
    for (int x1 = 0; x1 < n; x1++) {
        for (int y1 = 0; y1 < m; y1++) {
            for (int x2 = x1 + 1; x2 <= n; x2++) {
                for (int y2 = y1 + 1; y2 <= m; y2++) {
                    int t = sum[x2][y2] - sum[x2][y1] - sum[x1][y2] + sum[x1][y1];
                    if (t >= k) {
                        mi = min(mi, (x2 - x1) * (y2 - y1));
                    }
                }
            }
        }
    }
    cout << (mi == INT_MAX ? 0 : mi);
    return 0;
}