#include <bits/stdc++.h>
using namespace std;

int g[105][105], c[105], path[105][105], p[105];

void Path(int s, int t) {
    int k = path[s][t];
    if (k == -1) {
        cout << "-->" << t;
        return;
    }
    Path(s, k);
    Path(k, t);
}

int main(){
    int n, m;
    cin >> n;
    memset(g, 0x3f, sizeof g);
    memset(path, -1, sizeof path);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x != -1) g[i][j] = x;
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (g[i][k] + g[k][j] + c[k] < g[i][j]) {
                    g[i][j] = g[i][k] + g[k][j] + c[k];
                    path[i][j] = k;
                }
                else if (g[i][j] == g[i][k] + g[k][j] + c[k] && path[i][j] > path[i][k]) {
                    path[i][j] = k;
                }
            }
        }
    }
    int s = 0, t = 0, ans = 0;
    while (s != -1 && t != -1) {
        cin >> s >> t;
        if (s == -1 && t == -1) {
            break;
        }
        cout << "From " << s << " to " << t << " :" << endl;
        cout << "Path: " << s;
        Path(s, t);
        cout << "\nTotal cost : " << g[s][t] << endl << endl;
    }
    return 0;
}