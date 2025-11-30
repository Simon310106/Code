#include <bits/stdc++.h>
using namespace std;

struct game{
    int money, time;
}a[505];

int f[505], ans;

bool cmp(game a, game b) {
    return a.money > b.money;
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].time;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].money;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        for (int j = a[i].time; j > 0; j--) {
            if (!f[j]) {
                f[j] = 1;
                ans += a[i].money;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}