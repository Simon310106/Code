#include <bits/stdc++.h>
using namespace std;

int a[30][30];

int main(){
    int n;
    cin >> n;
    int x = 1, y = (n + 1) / 2;
    a[x][y] = 1;
    int px = x, py = y;
    for (int i = 2; i <= n * n; i++) {
        x = px - 1;
        y = py + 1;
        if (x == 0) x = n;
        else if (x == n + 1) x = 1;
        if (y == 0) y = n;
        else if (y == n + 1) y = 1;
        if (a[x][y] != 0) {
            x = px + 1;
            y = py;
        }
        a[x][y] = i;
        px = x;
        py = y;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}