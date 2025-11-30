#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int s[N], g[N], ans;

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> g[i];
    }
    sort(s, s + n);
    sort(g, g + m);
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (s[i] >= g[j]) {
            i++;
            j++;
            ans++;
        }
        else {
            i++;
        }
    }
    cout << ans;
    return 0;
}