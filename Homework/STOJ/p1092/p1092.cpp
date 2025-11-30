#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int cnt = 1;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            cnt++;
        }
        else {
            if (cnt == 1) {
                cout << s[i - 1];
            }
            else {
                cout << cnt << s[i - 1];
            }
            cnt = 1;
        }
    }
    if (cnt == 1) {
        cout << s[s.length() - 1];
    }
    else {
        cout << cnt << s[s.length() - 1];
    }
    return 0;
}