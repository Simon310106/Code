#include <bits/stdc++.h>
using namespace std;

int a[100005], n, k;

bool check(int x) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i] / x;
    }
    return sum >= k;
}

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 0, r = INT_MAX, ans = 0;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << ans << endl;
    return 0;
}