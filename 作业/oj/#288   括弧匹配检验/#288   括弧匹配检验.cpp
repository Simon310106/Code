#include <bits/stdc++.h>
using namespace std;

stack <int> a;

int main(){
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[') {
            a.push(s[i]);
        }
        else if (s[i] == ')') {
            if (!a.empty() && a.top() == '(') {
                a.pop();
            }
            else {
                cout << "Wrong";
                return 0;
            }
        }
        else if (s[i] == ']') {
            if (!a.empty() && a.top() == '[') {
                a.pop();
            }
            else {
                cout << "Wrong";
                return 0;
            }
        }
    }
    if (a.empty()) {
        cout << "OK";
    }
    else {
        cout << "Wrong";
    }
    return 0;
}
