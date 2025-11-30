#include <bits/stdc++.h>
using namespace std;

struct node {
    int x, y, step;
}p;

int time1[310][310], vis[310][310];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
queue<node> q;

int main(){
    int m;
    cin >> m;
    memset(time1, -1, sizeof(time1));
    for (int i = 1; i <= m; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        if (t < time1[x][y] || time1[x][y] == -1) {
            time1[x][y] = t;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && (time1[nx][ny] == -1 || t < time1[nx][ny])) {
                time1[nx][ny] = t;
            } 
        }
    }
    p.x = 0, p.y = 0, p.step = 0, vis[0][0] = 1;
    q.push(p);
    while (!q.empty()) {
        p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if (nx >= 0 && ny >= 0 && vis[nx][ny] == 0 && (time1[nx][ny] == -1 || p.step + 1 < time1[nx][ny])) {
                node now;
                now.x = nx, now.y = ny, now.step = p.step + 1;
                vis[nx][ny] = 1;
                q.push(now);
                if (time1[nx][ny] == -1) {
                    cout << now.step;
                    return 0;
                }
            }
        }
    }
    cout << -1;
    return 0;
}