#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ans[305][305];

int main(){
    int n;
    cin >> n;
    int x = 1, y = 1, d = 0;
    for (int i = 1; i <= n * n; i++) {
        ans[x][y] = i;
        if(x + dx[d] > 0 && y + dy[d] > 0 && x + dx[d] <= n && y + dy[d] <= n && ans[x + dx[d]][y + dy[d]] == 0) {
            x += dx[d];
            y += dy[d];
        }
        else {
            d = (d + 1) % 4;
            x += dx[d];
            y += dy[d];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}