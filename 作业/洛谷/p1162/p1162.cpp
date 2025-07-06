#include <bits/stdc++.h>
using namespace std;

int a[35][35];
int n;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int vis[35][35];

void dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= n + 2 || y >= n + 2 || a[x][y] == 1 || vis[x][y]) {
        return;
    }
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        dfs(x + dx[i], y + dy[i]);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            a[i][j] = 0;
            vis[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                vis[i][j] = 1;
            }
        }
    }
    dfs(0, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (vis[i][j] == 0 && a[i][j] == 0) {
                a[i][j] = 2;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}