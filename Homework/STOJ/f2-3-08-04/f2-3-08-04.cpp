#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;
int a[N];
int q[N], h, t;
int ans[N];

int main(){
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        while (h < t && a[q[t - 1]] >= a[i]) {
            t--;
        }
        q[t++] = i;
        while (h < t && q[h] <= i - k) {
            h++;
        }
        ans[i] = a[q[h]];
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}