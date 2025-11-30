#include <bits/stdc++.h>
using namespace std;

int a, p;
int ans;

int qpow(int b, int e) {
    if (e == 0) {
        return 1;
    }
    int r = qpow(b, e >> 1);
    r = 1ll * r * r % p;
    if (e & 1) {
        r = 1ll * r * b % p;
    }
    return r;
}

void check(int e) {
    if (qpow(a, e) == 1) {
        ans = 0;
    }
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        cin >> a >> p;
        ans = 1;
        int phi = p - 1, r = phi;
        for (int i = 2; i * i <= phi; i++) {
            if (phi % i == 0) {
                check (phi / i);
                while (r % i == 0) {
                    r /= i;
                }
            }
        }
        if (r > 1) {
            check (phi / r);
        }
        cout << (ans ? "Yes" : "No") << endl;
    }
    return 0;
}