#include <bits/stdc++.h>
using namespace std;

stack <int> a;
stack <char> b;

int main(){
    string s;
    getline(cin, s);
    int tmp = 0;
    for (int i = 0; i <= s.size(); i++) {
        if (isdigit(s[i])) {
            tmp = (tmp * 10 + s[i] - '0') % 10000;
        }
        else {
            a.push(tmp);
            tmp = 0;
            while (!(b.empty() || s[i] == '*' && b.top() == '+')) {
                int y = a.top();
                a.pop();
                int x = a.top();
                a.pop();
                int z = b.top();
                b.pop();
                if (z == '*') {
                    a.push(x * y % 10000);
                }
                else {
                    a.push((x + y) % 10000);
                }
            }
            b.push(s[i]);
        }
    }
    cout << a.top();
    return 0;
}