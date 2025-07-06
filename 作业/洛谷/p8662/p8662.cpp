#include <bits/stdc++.h>
using namespace std;

char a[1005][1005];
int n, flag, ans;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int vis[1005][1005];

bool check(int x, int y) {
    return a[x][y] == '#';
}

int dfs(int x, int y) {
    vis[x][y] = 1;
    if (check(x + 1, y) && check(x, y + 1) && check(x - 1, y) && check(x, y - 1)) {
        flag = 0;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (check(nx, ny) && !vis[nx][ny]) {
            dfs(nx, ny);
        }
    }
    a[x][y] = '.';
    return flag;
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (check(i, j)) {
                flag = 1;
                ans += dfs(i, j);
            }
        }
    }
    cout << ans;

    return 0;
}