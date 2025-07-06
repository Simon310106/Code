#include <bits/stdc++.h>
using namespace std;

const int N = 62530;
char a[N];

int main(){
    int cnt = 0;
    while (cin >> a[cnt] && a[cnt++] != 'E');
    int w = 0, l = 0;
    for (int i = 0; i < cnt; i++) {
        if (a[i] == 'W') {
            w++;
        }
        if (a[i] == 'L') {
            l++;
        }

        if (w >= 11 && abs(w - l) >= 2) {
            cout << w << ":" << l << endl;
            w = 0;
            l = 0;
        }
        else if (l >= 11 && abs(w - l) >= 2) {
            cout << w << ":" << l << endl;
            w = 0;
            l = 0;
        }
        else if (i == cnt - 1) {
            cout << w << ":" << l << endl;
        }
    }
    cout << endl;

    w = 0;
    l = 0;
    for (int i = 0; i < cnt; i++) {
        if (a[i] == 'W') {
            w++;
        }
        if (a[i] == 'L') {
            l++;
        }

        if (w >= 21 && abs(w - l) >= 2) {
            cout << w << ":" << l << endl;
            w = 0;
            l = 0;
        }
        else if (l >= 21 && abs(w - l) >= 2) {
            cout << w << ":" << l << endl;
            w = 0;
            l = 0;
        }
        else if (i == cnt - 1) {
            cout << w << ":" << l << endl;
        }
    }

    return 0;
}