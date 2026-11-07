#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int a[N];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int maxn = 0, mi = 0x3f3f3f3f;
    for (int i = 2; i <= n - 1; i++) {
        mi = min(mi, a[i]);
        maxn = max(maxn, a[i] - mi);
    }
    int diff = -0x3f3f3f3f;
    for (int i = 1; i < n; i++) {
        diff = max(diff, a[i] - a[i + 1]);
    }
    mi = 0x3f3f3f3f;
    for (int i = 3; i <= n - 1; i++) {
        mi = min(mi, a[i - 1]);
        diff = max(diff, a[i] - mi);
    }
    cout << a[n] - a[1] + max(maxn, diff);
    return 0;
}