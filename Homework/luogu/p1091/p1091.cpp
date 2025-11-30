#include <bits/stdc++.h>
using namespace std;

int n, a[105], up[105], down[105];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        up[i] = 1;
        for (int j = 1; j <= i; j++) {
            if (a[j] < a[i]) {
                up[i] = max(up[i], up[j] + 1);
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        down[i] = 1;
        for (int j = n; j >= i; j--) {
            if (a[j] < a[i]) {
                down[i] = max(down[i], down[j] + 1);
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, n - (up[i] + down[i] - 1));
    }
    cout << ans << endl;
    return 0;
}