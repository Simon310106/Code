#include <bits/stdc++.h>
using namespace std;

struct node {
    int start, end, milk;
}a[1005];

int n, m, r, dp[1005];

bool cmp(node x, node y) {
    if (x.end != y.end) {
        return x.end < y.end;
    }
    return x.start < y.start;
}

int main(){
    cin >> n >> m >> r;
    for (int i = 1; i <= m; i++) {
        cin >> a[i].start >> a[i].end >> a[i].milk;
    }
    sort(a + 1, a + m + 1, cmp);
    dp[0] = 0;
    for (int i = 1; i <= m; i++) {
        dp[i] = dp[i - 1];
        int p = 0;
        for (int j = i - 1; j >= 1; j--) {
            if (a[j].end + r <= a[i].start) {
                p = j;
                break;
            }
        }
        dp[i] = max(dp[i], dp[p] + a[i].milk);
    }
    cout << dp[m] << endl;
    return 0;
}