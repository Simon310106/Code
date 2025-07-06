#include <bits/stdc++.h>
using namespace std;

struct milk{
    int start, end, eff;
}a[1005];

bool cmp(milk x, milk y){
    return x.end < y.end; 
}

int dp[1005];

int main(){
    int n, m, r;
    cin >> n >> m >> r;
    for (int i = 1; i <= m; i++) {
        cin >> a[i].start >> a[i].end >> a[i].eff;
    }
    sort(a + 1, a + m + 1, cmp);
    a[0].end = 0;
    dp[0] = 0;
    for (int i = 1; i <= m; i++) {
        int l = 0, rr = i - 1, pre = 0;
        while (l <= rr) {
            int mid = (l + rr) / 2;
            if (a[mid].end + r <= a[i].start) {
                pre = mid;
                l = mid + 1;
            } else {
                rr = mid - 1;
            }
        }
        dp[i] = max(dp[i - 1], dp[pre] + a[i].eff);
    }
    cout << dp[m] << endl;
    return 0;
}