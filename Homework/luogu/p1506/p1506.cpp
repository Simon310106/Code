#include <bits/stdc++.h>
using namespace std;

int dx[10] = {0, 0, -1, 1};
int dy[10] = {1, -1, 0, 0};
int n, m, gs;
char ch[510][510];

void dfs(int x, int y)
{
    if (x < 0 || y < 0 || x > n + 1 || y > m + 1 || ch[x][y] == '*')
        return;
    ch[x][y] = '*';
    for (int i = 0; i < 4; i++)
        dfs(x + dx[i], y + dy[i]);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> ch[i][j];
        }
    }
    dfs(0, 0);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (ch[i][j] == '0')
            {
                gs++;
            }
        }
    }
    cout << gs;
    return 0;
}