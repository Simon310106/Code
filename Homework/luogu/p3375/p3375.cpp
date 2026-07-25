#include <bits/stdc++.h>
using namespace std;

int nxt[1000005];

int main(){
    string s, p;
    cin >> s >> p;
    int n = s.size(), m = p.size();
    s = " " + s;
    p = " " + p;
    for (int i = 2, j = 0; i <= m; i++) {
        while (j && p[i] != p[j + 1]) j = nxt[j];
        if (p[i] == p[j + 1]) {
            j++;
        }
        nxt[i] = j;
    }
    for (int i = 1, j = 0; i <= n; i++) {
        while (j && s[i] != p[j + 1]) j = nxt[j];
        if (s[i] == p[j + 1]) {
            j++;
        }
        if (j == m) {
            cout << i - m + 1 << endl;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << nxt[i] << " ";
    }
    return 0;
}