#include <bits/stdc++.h>
using namespace std;

int dp[1000005];
int ma, pos;

int main(){
    string s;
    cin >> s;
    s = "  " + s;
    int n = s.size();
    for (int i = 2; i < n; i++) {
        if (s[i] == ')') {
            if (s[i - 1] == '[') continue;
            int p = i - dp[i - 1] - 1;
            if (p >= 0 && s[p] == '(') 
                dp[i] = dp[i - 1] + 2 + dp[p - 1];
        }
        else if (s[i] == ']') {
            if (s[i - 1] == '(') continue;
            int p = i - dp[i - 1] - 1;
            if (p >= 0 && s[p] == '[') 
                dp[i] = dp[i - 1] + 2 + dp[p - 1];
        }
        if (ma < dp[i]) {
            ma = dp[i];
            pos = i;
        }
    }
    cout << s.substr(pos - ma + 1, ma);
    return 0;
}