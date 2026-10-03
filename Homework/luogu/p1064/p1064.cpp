#include <bits/stdc++.h>
using namespace std;

int c[65][3], p[65][3], f[65][32005];

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int v, w, q;
        cin >> v >> w >> q;
        if (q) {
            if (!c[q][1]) {
                c[q][1] = v;
                p[q][1] = w;
            }
            else {
                c[q][2] = v;
                p[q][2] = w;
            }
        }
        else {
            c[i][0] = v;
            p[i][0] = w;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = n; j >= 0; j--) {
            f[i][j] = f[i - 1][j];
            if (!c[i][0]) continue;
            if (c[i][0] <= j) 
                f[i][j] = max(f[i][j], f[i - 1][j - c[i][0]] + c[i][0] * p[i][0]);
            if (c[i][1] && c[i][0] + c[i][1] <= j) 
                f[i][j] = max(f[i][j], f[i - 1][j - c[i][0] - c[i][1]] + c[i][0] * p[i][0] + c[i][1] * p[i][1]);
            if (c[i][2] && c[i][0] + c[i][2] <= j) 
                f[i][j] = max(f[i][j], f[i - 1][j - c[i][0] - c[i][2]] + c[i][0] * p[i][0] + c[i][2] * p[i][2]);
            if (c[i][1] && c[i][2] && c[i][0] + c[i][1] + c[i][2] <= j) 
                f[i][j] = max(f[i][j], f[i - 1][j - c[i][0] - c[i][1] - c[i][2]] + c[i][0] * p[i][0] + c[i][1] * p[i][1] + c[i][2] * p[i][2]);
        }
    }
    cout << f[m][n] << endl;
    return 0;
}