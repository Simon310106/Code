#include <bits/stdc++.h>
using namespace std;

int s[25][25][25], ans;

int main(){
    int w, x, h, q;
    cin >> w >> x >> h >> q;
    for (int i = 0; i < q; i++) {
        int x1, x2, y1, y2, z1, z2;
        scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
        for (int a = min(x1, x2); a <= max(x1, x2); a++) {
            for (int b = min(y1, y2); b <= max(y1, y2); b++) {
                for (int c = min(z1, z2); c <= max(z1, z2); c++) {
                    s[a][b][c] = 1;
                }
            }
        }
    }
    for (int a = 1; a <= w; a++) {
        for (int b = 1; b <= x; b++) {
            for (int c = 1; c <= h; c++) {
                if (!s[a][b][c]) {
                    ans++;
                }
            }
        }
    }
    cout << ans;

    return 0;
}