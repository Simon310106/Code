#include <bits/stdc++.h>
using namespace std;

char a[300];

int main(){
    int cnt = 0;
    while (cin >> a[cnt]) {
        if (a[cnt++] == '@') {
            break;
        }
    }
    if (a[0] == ')') {
        cout << "NO";
        return 0;
    }
    int l = 0, r = 0, x = 0, y = 0;
    for (int i = 0; i < cnt; i++) {
        if (a[i] == '(') {
            l++;
        }
        if (a[i] == ')') {
            if (l > 0) {
                l--;
            }
            else {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << (l == 0 ? "YES" : "NO");
    return 0;
}