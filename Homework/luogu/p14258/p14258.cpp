#include <bits/stdc++.h>
using namespace std;

int T;
string b;

int main(){
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cin >> b;
        int ans = 0;
        int l = 0, r = n - 1;
        while (r >= 0 && b[r] == '0') {
            r--;
        }
        if (b[l] == '1') {
            b[l] = '0';
            ans++;
        }
        while (l <= r) {
            while (r >= 0 && b[r] == '0') {
                r--;
            }
            if (b[r] == '1') {
                b[r] = '0';
                r--;
                l++;
                ans += (r - l + 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}