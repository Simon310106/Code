#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, a;
    getline(cin, s);
    getline(cin, a);
    int cnt = 1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            while (s[i] == ' ' && i < s.length()) {
                i++;
            }
            cnt++;
        }
        if (s[i] == a[0] && s.substr(i, a.length()) == a) {
            cout << cnt;
            return 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ' && s[i] != '.') {
            ans++;
        }
    }
    cout << ans;
    return 0;
}