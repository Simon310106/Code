#include <bits/stdc++.h>
using namespace std;

int a[1005], ma = 0, mi = 0x3f3f3f3f, ans = a[0];

int main(){
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 1; i < n; i++) {
        int sum = 0;
        for (int j = 0; j <= i; j++) {
            if (a[i] - a[j] <= k) {
                sum += a[j];
            }
        }
        ans = max(ans, sum);
    }
    cout << ans;

    return 0;
}