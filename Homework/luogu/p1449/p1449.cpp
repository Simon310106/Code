#include <bits/stdc++.h>
using namespace std;

stack<long long> ans;

int main(){
    string s;
    cin >> s;
    int now = 0;
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            now = now * 10 + (s[i] - '0');
        }
        else if (s[i] == '.') {
            ans.push(now);
            now = 0;
        }
        else if (!isdigit(s[i]) && s[i] != '.' && s[i] != '@') {
            long long b = ans.top();
            ans.pop();
            long long a = ans.top();
            ans.pop();
            if (s[i] == '+') {
                ans.push(a + b);
            }
            else if (s[i] == '-') {
                ans.push(a - b);
            }
            else if (s[i] == '*') {
                ans.push(a * b);
            }
            else if (s[i] == '/') {
                ans.push(a / b);
            }
        }
    }
    cout << ans.top() << endl;
    return 0;
}