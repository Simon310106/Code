#include <bits/stdc++.h>
using namespace std;

struct node{
    int x, y, step;
    node (int a = 0, int b = 0, int c = 0) {
        x = a, y = b, step = c;
    }
};

queue<node> q;
int nx, ny;
int vis[55][55];
int dx[12] = {-2, -1, 1, 2, 2, 2, 2, 1, -1, -2, -2, -2};
int dy[12] = {2, 2, 2, 2, 1, -1, -2, -2, -2, -2, -1, 1};

int bfs(int x, int y){
    memset(vis, 0, sizeof(vis));
    while (!q.empty()) q.pop();
    
    node tmp;
    q.push(node(x, y, 0));
    vis[x][y] = 1;
    
    while (!q.empty()) {
        node n = q.front();
        q.pop();
        
        if (n.x == nx && n.y == ny) {
            return n.step;
        }
        
        for (int i = 0; i < 12; i++) {
            int tx = n.x + dx[i], ty = n.y + dy[i];
            if (tx > 0 && ty > 0 && tx <= 50 && ty <= 50 && !vis[tx][ty]) {
                q.push(node(tx, ty, n.step + 1));
                vis[tx][ty] = 1;
            }
        }
    }
}

int main(){
    cin >> nx >> ny;
    cout << bfs(1, 1) << endl;
    
    cin >> nx >> ny;
    cout << bfs(1, 1) << endl;
    
    return 0;
}