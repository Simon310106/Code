#include <bits/stdc++.h>
using namespace std;

stack <char> s;

int main(){
    string a;
    cin >> a;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '(') {
            s.push('(');
        }
        else if (a[i] == ')') {
            if (s.empty()) {
                cout << "NO";
                return 0;
            }
            else {
                s.pop();
            }
        }
    }
    if (!s.empty()) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }
    return 0;
}