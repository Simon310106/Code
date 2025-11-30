#include <bits/stdc++.h>
using namespace std;

bool vis[200005];

int main(){
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        if (x >= y) {
            cout << x - y << endl;
            continue;
        }

        memset(vis, 0, sizeof(vis));
        queue<pair<int, int>> q;
        q.push({x, 0});
        vis[x] = 1;
        while (!q.empty()) {
            pair<int, int> temp = q.front();
            int pos = temp.first;
            int step = temp.second;
            q.pop();
            if (pos == y) {
                cout << step << endl;
                break;
            }
            int a = pos + 1;
            int b = pos - 1;
            int c = pos * 2;
            if (a <= 200000 && !vis[a]) {
                vis[a] = 1;
                q.push({a, step + 1});
            }
            if (b >= 0 && !vis[b]) {
                vis[b] = 1;
                q.push({b, step + 1});
            }
            if (c <= 200000 && !vis[c]) {
                vis[c] = 1;
                q.push({c, step + 1});
            }
        }
    }
    return 0;
}