#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;
int n, k, a[N];
int h, t;
int ans[N], q[N];

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        while (h < t && a[q[t - 1]] <= a[i]) {
            t--;
        }
        q[t++] = i;
        while (h < t && q[h] <= i - k) {
            h++;
        }
        if (i >= k) ans[i - k] = a[q[h]];
    }
    for (int i = 0; i <= n - k; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}