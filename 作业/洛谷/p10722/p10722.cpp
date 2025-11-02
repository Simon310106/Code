#include <bits/stdc++.h>
using namespace std;

int n, q, p[100005], a[100005], b[100005];
string s;

int dfs(int x) {
    if (b[x] > 0) {
        return b[x];
    }
    b[x] = a[x] + dfs(p[x]);
    return b[x];
}

int main(){
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
    }
    cin >> s >> q;
    for (int i = 1; i <= q; i++) {
        int tmp;
        cin >> tmp;
        a[tmp]++;
    }
    b[1] = a[1] + 2;
    for (int i = 1; i <= n; i++) {
        if (!b[i]) {
            dfs(i);
        }
    }
    for (int i = 0; i < n; i++) {
        bool x = s[i] - '0';
        if (b[i + 1] % 2 == 0) {
            cout << x;
        }
        else {
            cout << !x;
        }
    }
    return 0;
}