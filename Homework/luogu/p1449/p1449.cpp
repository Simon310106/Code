#include <bits/stdc++.h>
using namespace std;

stack<long long> ans;

int main(){
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '.' && !isdigit(s[i]) && s[i] != '@') {
            long long a = ans.top() - '0';
            ans.pop();
            long long b = ans.top() - '0';
            ans.pop();
            if (s[i] == '+') {
                ans.push(b + a);
            } if (s[i] == '-') {
                ans.push(b - a);
            } if (s[i] == '*') {
                ans.push(b * a);
            } if (s[i] == '/') {
                ans.push(b / a);
            }
        }
        if (isdigit(s[i])) {
            long long tmp = 0;
            while (isdigit(s[i])) {
                tmp = tmp * 10 + (s[i] - '0');
                i++;
            }
            ans.push(tmp);
        }
    }
    cout << ans.top() << endl;
    return 0;
}