#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int a = 0, b = 0, tmp;
    for (int i = 0; i <= s.size(); i++) {
        if (isdigit(s[i])) {
            a = a * 10 + s[i] - '0';
        }
        else if (s[i] == '+') {
            tmp = i + 1;
            break;
        }
    }
    for (int i = tmp; i <= s.size(); i++) {
        if (isdigit(s[i])) {
            b = b * 10 + s[i] - '0';
        }
        else if (s[i] == '=') {
            break;
        }
    }
    cout << a + b;
    
    return 0;
}
