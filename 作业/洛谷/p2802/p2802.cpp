#include <bits/stdc++.h>
using namespace std;

struct node {
    int x, y, step, hp;
};

int n, m, sx, sy;
int a[55][55];
int vis[55][55];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
queue <node> q;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) {
                sx = i;
                sy = j;
            }
            if (a[i][j] == 0) {
                vis[i][j] = 1;
            }
        }
    }
    q.push({sx, sy, 0, 6});
    vis[sx][sy] = 1;
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        if (a[now.x][now.y] == 3) {
            cout << now.step << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (vis[nx][ny]) continue;
            int nhp = now.hp - 1;
            if (nhp <= 0) continue;
            if (a[nx][ny] == 4) {
                nhp = 6;
            }
            q.push({nx, ny, now.step + 1, nhp});
            vis[nx][ny] = 1;
        }
    }
    cout << -1 << endl;
    return 0;
}