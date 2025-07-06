#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, ans;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) {
            while (i < s.length() && !isdigit(s[i])) {
                i++;
            }
            i--;
            ans += '*';
        }
        else {
            ans += s[i];
        }
    }
    cout << ans;
    return 0;
}