#include <bits/stdc++.h>
using namespace std;
vector<int> g[105];
queue<int> q;
int indeg[105];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        while(cin >> x && x) {
            g[i].push_back(x);
            indeg[x]++;
        }
    }
    // 入度为0的加入队列;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    // top sort
    while(!q.empty()) {
        int t = q.front(); q.pop();
        cout << t << " ";
        for (int v : g[t]) {
            indeg[v]--;
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
    }
    return 0;
}