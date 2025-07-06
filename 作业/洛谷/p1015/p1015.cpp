#include <bits/stdc++.h>
using namespace std;

const int N = 1e+6 + 10;
int a[N], c[N], ans[N], m;
string n;

void add() {
    int b[N] = {}, x = 0;
    for (int i = 1; i <= a[0]; i++) {
        b[i] = a[a[0] - i + 1];
    }
    for (int i = 1; i <= a[0]; i++) {
        a[i] = a[i] + b[i] + x;
        x = a[i] / m;
        a[i] %= m;
    }
    if (x) {
        a[++a[0]] = x;
    }
}

bool check_hw(string s) {
    string t = s;
    reverse(s.begin(), s.end());
    if (s == t) {
        return 1;
    }
    return 0;
}

void change(int m) {
    a[0] = n.length();
    for (int i = 1; i <= a[0]; i++) {
        if (n[i] >='0' && n[i] <= '9') {
            a[i] = n[a[0] - i] - '0';
        }
        else if (n[i] >= 'A' && n[i] <= 'Z') {
            a[i] = n[a[0] - i] - 'A' + 10;
        }
        else {
            a[i] = n[a[0] - i] - 'a' + 10;
        }
    }
}

int main(){
    int a1;
    string sum;
    int t = 0;
    cin >> a1 >> n;
    change(a1);
    if (check_hw(n)) {
        cout << "STEP=0";
        return 0;
    }
    while (t <= 30) {
        t++;
        add();
        if (check_hw(sum)) {
            cout << "STEP=" << t << endl;
            return 0;
        }
    }
    cout << "Impossible!";
    return 0;
}