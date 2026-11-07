#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int n;
char a[N];
int cnt[N];

signed main(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cnt[i] >> a[i];
    }
    int l = 1, r = n, ans = 0;
    while (l < r) {
        int t = min(cnt[l], cnt[r]);
        if (a[l] != a[r]) ans += t;
        cnt[l] -= t;
        cnt[r] -= t;
        if (cnt[l] == 0) l++;
        if (cnt[r] == 0) r--;
    }
    cout << ans << endl;
    return 0;
}