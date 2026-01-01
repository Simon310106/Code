#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, s, t;
const int MAXN = 1e12;

signed main(){
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        if (c == 'U') {
            if (s == 1) {
                continue;
            }
            if (t) {
                t--;
                continue;
            }
            s /= 2;
        }
        else if (c == 'L') {
            if (s * 2 >= MAXN) {
                t++;
            }
            else {
                s *= 2;
            }
        }
        else if (c == 'R') {
            if (s * 2 + 1 >= MAXN) {
                t++;
            }
            else {
                s = s * 2 + 1;
            }
        }
    }
    cout << s << endl;
    return 0;
}