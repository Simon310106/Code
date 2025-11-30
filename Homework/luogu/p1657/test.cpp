#include <bits/stdc++.h>
using namespace std;

int x, total = 0;
int a[25][3];
bool vis[25];

void dfs(int k) {
    if (k == x + 1) {
        total++;
        return;
    }
    for (int i = 1; i <= 2; i++) {
        if (!vis[a[k][i]]) {
            vis[a[k][i]] = true;
            dfs(k + 1);
            vis[a[k][i]] = false;
        }
    }
}

int main(){
    cin >> x;
    for (int i = 1; i <= x; i++) {
        cin >> a[i][1] >> a[i][2];
    }
    dfs(1);
    cout << total;
    return 0;
}