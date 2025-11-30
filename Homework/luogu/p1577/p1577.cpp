#include <bits/stdc++.h>
using namespace std;

double a[10005];
int n, k;

bool check(double x) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += int(a[i] / x);
    }
    return sum >= k;
}

int main(){
    cin >> n >> k;
    double ma = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ma = max(ma, a[i]);
    }
    double l = 0, r = ma, ans = 0;
    while (r - l > 1e-4) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}