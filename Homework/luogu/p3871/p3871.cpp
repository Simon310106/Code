#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, cnt;

int main() {
    cin >> n;
    for (ll i = 2; i * i <= n; i++) {
        cnt = 0;
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
            if (cnt == 1)
                cout << i;
            else
                cout << i << '^' << cnt;
            if (n > 1)
                cout << " * ";
        }
    }
    if (n > 1)
        cout << n;
    return 0;
}