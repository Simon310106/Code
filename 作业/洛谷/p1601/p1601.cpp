#include <bits/stdc++.h>
using namespace std;

int a[550], b[550], c[550];

string add(string a1, string b1) {
    int lena = a1.length();
    int lenb = b1.length();
    for (int i = 0; i < lena; i++) {
        a[lena - i] = a1[i] - '0';
    }
    for (int i = 0; i < lenb; i++) {
        b[lenb - i] = b1[i] - '0';
    }
    int lenc = 1;
    int x = 0;
    while (lenc <= lena || lenc <= lenb) {
        c[lenc] = a[lenc] + b[lenc] + x;
        x = c[lenc] / 10;
        c[lenc] %= 10;
        lenc++;
    }
    c[lenc] = x;
    if (!c[lenc]) {
        lenc--;
    }
    string ans = "";
    for (int i = lenc; i >= 1; i--) {
        ans += char(c[i] + '0');
    }
    return ans;
}

int main(){
    string a1, b1;
    cin >> a1 >> b1;
    cout << add(a1, b1);
    return 0;
}