#include <bits/stdc++.h>
using namespace std;

int n, a[100005];
long long ans = 0;

int main(){
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    while (n > 3) {
        ans += min(a[1] + a[2] * 2 + a[n], a[1] * 2 + a[n] + a[n - 1]);
        n -= 2;
    }
    if (n == 2) {
        ans += a[2];
    }
    else if (n == 3) {
        ans += a[1] + a[2] + a[3];
    }
    cout << ans << endl;

    return 0;
}