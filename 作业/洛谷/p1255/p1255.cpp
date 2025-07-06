#include <bits/stdc++.h>
using namespace std;

int a[1000050] = {0, 1}, b[1000050] = {0, 0}, c[1000050] = {0, 0}, ans[1000050];
int lena = 1;
int lenb = 1;
int lenc = 1;
int x = 0;

void add() {
    x = 0;
    lenc = 1;
    while (lenc <= lena || lenc <= lenb) {
        c[lenc] = a[lenc] + b[lenc] + x;
        x = c[lenc] / 10;
        c[lenc] %= 10;
        lenc++;
    }
    c[lenc] = x;
    while (c[lenc] == 0 && lenc > 1) {
        lenc--;
    }
}

int main(){
    int n;
    cin >> n;
    n++;
    for (int i = 2; i <= n; i++) {
        add();
        for (int i = 1; i <= lenc; i++) {
            b[i] = a[i];
            a[i] = c[i];
        }
        lena = lenb = lenc;
    }
    for (int i = lenc; i >= 1; i--) {
        cout << c[i];
    }
    return 0;
}