#include <bits/stdc++.h>
using namespace std;

int nxt[1005];

int main(){
    string s = "", p = "";
    while (s != "#") {
        cin >> s;
        if (s == "#") break;
        cin >> p;
        int ans = 0;
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
                ans++;
                j = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}