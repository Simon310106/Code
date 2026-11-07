#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m;
int a[N];

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int bit = 29; bit >= 0; bit--) {
        int want = ans | (1 << bit);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if ((a[i] & want) == want) cnt++;
        }
        if (cnt >= m) ans = want;
    }
    cout << ans << endl;
    return 0;
}