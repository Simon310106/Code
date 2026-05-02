#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9;

signed main(){
    int T;
    cin >> T;
    while (T--) {
        int n, ans = 1;
        cin >> n;
        while (n % 3 == 0 && n > 0) {
            n -= 3;
            ans *= 3;
            ans %= mod;
        }
        while (n % 2 == 0 && n > 0) {
            n -= 2;
            ans *= 2;
            ans %= mod;
        }
        cout << ans % mod << endl;
    }
    return 0;
}
/*
1 1     1
2 2     2
3 3     3
4 4     2 * 2
5 6     2 * 3
6 9     3 * 3
7 12    3 * 2 * 2
8 18    3 * 3 * 2
9 27    3 * 3 * 3
10 36   3 * 3 * 2 * 2;
*/