#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], ans;

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    while (n >= 4) {
        ans += min(2 * a[1] + a[n - 1] + a[n], a[1] + 2 * a[2] + a[n]);
        n -= 2;
    }
    if (n == 3) {
        ans += a[1] + a[2] + a[3];
    }
    else if (n == 2) {
        ans += a[2];
    }
    else if (n == 1) {
        ans += a[1];
    }
    cout << ans;
    return 0;
}