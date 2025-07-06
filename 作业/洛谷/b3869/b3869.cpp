#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[1050];

int main(){
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        ll k;
        string s;
        cin >> k >> s;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] <= '9' && s[j] >= '0') {
                a[j] = s[j] - '0';
            }
            else {
                a[j] = s[j] - 'A' + 10;
            }
        }
        ll result = 0;
        for (int j = s.length() - 1; j >= 0; j--) {
            result += a[j] * pow(k, s.length() - 1 - j);
        }
        cout << result << endl;
        
    }
    
    return 0;
}
