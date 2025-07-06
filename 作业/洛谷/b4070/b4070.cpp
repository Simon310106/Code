#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[1000005], ans;

ll fun(ll n) {
    ll ans = 0, t = 1;
    while (n >= t) {
        n -= t;
        t++;
        ans++;
    }
    return ans;
}

int main(){
    ll n;
    cin >> n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ll cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            ans += fun(cnt);
        }
    }
    if (n != 1) {
        ans++;
    }
    cout << ans;
    return 0;
}