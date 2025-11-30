#include <bits/stdc++.h>
using namespace std;

int ans[15], a[15];

int main(){
    int n, k;
    cin >> n >> k;
    int cnt = 0, t = n;
    while (t != 0) {
        cnt++;
        t /= 10;
    }
    for (int i = cnt; i >= 1; i--) {
        int tmp = n % int(pow(10, i));
        a[i] = tmp;
    }
    for (int i = 1; k != 0; ) {
        if (a[i] <= a[i + 1]) {
            ans[i] = a[i];
            i++;
        }
        else {
            k--;
        }
    }
    for (int i = 1; i <= cnt; i++) {
        cout << ans[i];
    }
    return 0;
}