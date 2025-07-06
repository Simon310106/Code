#include <bits/stdc++.h>
using namespace std;


int main(){
    while (1) {
        int n;
        cin >> n;
        stack <int> a;
        if (n == 0) {
            break;
        }
        for (int i = 1; i <= n; i++) {
            char c;
            cin >> c;
            if (c == 'P') {
                int t;
                cin >> t;
                a.push(t);
            }
            else if (c == 'O') {
                if (!a.empty()) {
                    a.pop();
                }
            }
            else if (c == 'A') {
                if (!a.empty()) {
                    cout << a.top() << endl;
                }
                else {
                    cout << 'E' << endl;
                }
            }
        }
        cout << endl;
    }
    return 0;
}