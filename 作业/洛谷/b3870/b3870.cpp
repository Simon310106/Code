#include <bits/stdc++.h>
using namespace std;

long long n, cnt, j;
bool b[105], c[15];
string s, ans;

void btoh() {
    s = "";
    int tmp = 0;
    for (int i = 0; i < 4; i++) {
        if (c[i] == 1) {
            tmp += pow(2, i);
        }
    }
    if (tmp <= 9) {
        s = char(tmp + '0') + s;
    }
    else {
        s = char(tmp - 10 + 'A') + s;
    }
    tmp = 0;
    for (int i = 4; i < 8; i++) {
        if (c[i] == 1) {
            tmp += pow(2, i - 4);
        }
    }
    if (tmp <= 9) {
        s = char(tmp + '0') + s;
    }
    else {
        s = char(tmp - 10 + 'A') + s;
    }

}

int main(){
    cin >> n;
    if (n == 0) {
        cout << "00";
        return 0;
    }
    while (n > 0) {
        b[cnt++] = n & 1;
        n = n >> 1;
    }
    for (int i = 0; i < cnt; i++) {
        c[j++] = b[i];
        if (i == cnt - 1) {
            c[7] = 0;
            btoh();
            ans += s;
            memset(c, 0, sizeof(c));
        }
        else if (j == 7) {
            c[7] = 1;
            btoh();
            ans += s + " ";
            memset(c, 0, sizeof(c));
            j = 0;
        }
    }
    cout << ans;
    return 0;
}
