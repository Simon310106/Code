#include <bits/stdc++.h>
using namespace std;

int m[1050][1050], n;

void p(int a, int b, int c, int d) {
    for (int i = a; i <= (a + c) / 2; i++) {
        for (int j = b; j <= (b + d) / 2; j++) {
            m[i][j] = 0;
        }
    }
    if (a == (a + c) / 2) {
        return;
    }
    p((a + c + 1) / 2, b, c, (b + d - 1) / 2);
    p(a, (d + b + 1) / 2, (c + a - 1) / 2, d);
    p((a + c + 1) / 2, (b + d + 1) / 2, c, d);
}

int main(){
    int n;
    cin >> n;
    int t = pow(2, n);
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= t; j++) {
            m[i][j] = 1;
        }
    }
    p(1, 1, t, t);
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= t; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}