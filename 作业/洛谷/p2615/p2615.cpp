#include <bits/stdc++.h>
using namespace std;

int a[45][45];

void write(int n) {
    int s = (n + 1) / 2;
    a[1][s] = 1;
    int x = 1;
    int y = s;
    int cnt = 2;
    for (int k = 2; k <= n * n; k++) {
        if (x == 1 && y != n) {
            x = n;
            y++;
            a[x][y] = cnt;
            cnt++;
        }
        else if (y == n && x != 1) {
            x--;
            y = 1;
            a[x][y] = cnt;
            cnt++;
        }
        else if (x == 1 && y == n) {
            x++;
            a[x][y] = cnt;
            cnt++;
        }
        else {
            if (a[x - 1][y + 1] == 0) {
                x--;
                y++;
                a[x][y] = cnt;
                cnt++;
            }
            else {
                x++;
                a[x][y] = cnt;
                cnt++;
            }
        }
            
    }
}

int main(){
    int n;
    cin >> n;
    write(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}