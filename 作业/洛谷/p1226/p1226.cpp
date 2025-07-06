#include <bits/stdc++.h>
#define ll long long
using namespace std;

long long qpw(ll x, ll n, ll k) {
    ll ans = 1;
    while (n) {
        if (n & 1) {
            ans *= x;
        }
        x = x * x;
        x %= k;
        n >>= 1;
        ans %= k;
    }
    return ans;
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    cout << n << "^" << m << " mod " << k << "=" << qpw(n, m, k);
    return 0;
}