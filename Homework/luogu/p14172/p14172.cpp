#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while (T--) {
        stack<long long> s;
        int n, cnt = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            char c;
            cin >> c;
            if (c == ')' && !s.empty() && s.top() == '(') {
                s.pop();
            }
            else if (c == '(' && !s.empty() && s.top() == ')' && !cnt) {
                s.pop();
                cnt++;
            }
            s.push(c);
        }
        if (!s.empty()) {
            cout << "No" << endl;
        }
        else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}