#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while (T--) {
        string s;
        stack<char> a;
        cin >> s;
        bool f = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                a.push(s[i]);
            }
            else if (s[i] == ')') {
                if (!a.empty() && a.top() == '(') {
                    a.pop();
                }
                else {
                    cout << "NO" << endl;
                    f = true;
                    break;
                }
            }
            else if (s[i] == ']') {
                if (!a.empty() && a.top() == '[') {
                    a.pop();
                }
                else {
                    cout << "NO" << endl;
                    f = true;
                    break;
                }
            }
            else if (s[i] == '}') {
                if (!a.empty() && a.top() == '{') {
                    a.pop();
                }
                else {
                    cout << "NO" << endl;
                    f = true;
                    break;
                }
            }
            else {
                cout << "NO" << endl;
                f = 1;
                break;
            }
        }
        if (a.empty() && !f) {
            cout << "YES" << endl;
        }
        else if (!f){
            cout << "NO" << endl;
        }
    }
    
    return 0;
}