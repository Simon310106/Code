#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
    if (n == 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        if (is_prime(h)) {
            cout << 1 << endl;
            continue;
        }
        for (int i = 1; i >= 1; i++) {
            h -= pow(2, i - 1);
            if (h < 0) {
                cout << -1 << endl;
                break;
            }
            if (h == 0) {
                cout << i << endl;
                break;
            }
            if (h > 0 && is_prime(h)) {
                cout << i + 1 << endl;
                break;
            }
        }
    }
    return 0;
}