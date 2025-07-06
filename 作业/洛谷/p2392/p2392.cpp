#include <bits/stdc++.h>
using namespace std;

int a[5];
int t[4][22];
bool vis[4][22];
int l, r, mi;

void dfs(int i, int j) {
    if (j >= a[i]) {
        mi = min(mi, max(l, r));
        return;
    }
    l += t[i][j];
    dfs(i, j + 1);
    l -= t[i][j];
    r += t[i][j];
    dfs(i, j + 1);
    r -= t[i][j];
}

int main(){
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < a[i]; j++) {
            cin >> t[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        mi = INT_MAX;
        l = r = 0;
        memset(vis, false, sizeof(vis));
        dfs(i, 0);
        ans += mi;
    }
    cout << ans << endl;
    return 0;
}