#include <bits/stdc++.h>
#define ll long long
using namespace std;

stack <ll> a;

int main(){
    string s;
    getline(cin, s);
    ll i = 0, tmp = 0;
    while (s[i] != '@') {
        if (isdigit(s[i])) {
            tmp = tmp * 10 + s[i] - '0';
        }
        else if (s[i] == ' ') {
            a.push(tmp);
            tmp = 0;
        }
        else {
            ll y = a.top();
            a.pop();
            ll x = a.top();
            a.pop();
            if (s[i] == '+') {
                a.push(x + y);
            }
            else if (s[i] == '-') {
                a.push(x - y);
            }
            else if (s[i] == '*') {
                a.push(x * y);
            }
            else if (s[i] == '/') {
                a.push(x / y);
            }
        }
        i++;
    }
    cout << a.top();

    return 0;
}