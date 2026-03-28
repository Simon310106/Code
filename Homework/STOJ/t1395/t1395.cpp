#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> g[100];
queue<int> q;
int indeg[100];
int slide[100][5];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> slide[i][1] >> slide[i][2] >> slide[i][3] >> slide[i][4]; 
    }
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        for (int j = 1; j <= n; j++) {
            if (x >= slide[j][1] && x <= slide[j][2] && y >= slide[j][3] && y <= slide[j][4]) {
                indeg[i]++;
                g[j].push_back(i);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 1) {
            q.push(i);
        }
    }
    // int cnt = 0;
    while (!q.empty()) {
        int t = q.front(); q.pop();
        // cnt++;
        cout << t << endl;
        for (int v : g[t]) {
            indeg[v]--;
            if (indeg[v] == 1) {
                q.push(v);
            }
        }
    }
    return 0;
}