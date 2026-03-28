#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 5e5 + 5;
int st[MAXN][20];
int lg2[MAXN] = {-1};
int sum[MAXN];
int p[MAXN];

signed main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
        st[i][0] = sum[i];
        lg2[i] = lg2[i / 2] + 1;
    }
    for (int j = 1; j <= lg2[n]; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    int ans = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        int l = max(0ll, i - m);
        int r = i - 1;
        int k = r - l + 1;
        int tmp = sum[i] - min(st[l][lg2[k]], st[r - (1 << lg2[k]) + 1][lg2[k]]);
        ans = max(tmp, ans);
    }
    cout << ans << endl;
    return 0;
}