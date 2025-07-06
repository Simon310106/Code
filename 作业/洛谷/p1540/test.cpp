#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int ans;
int vis[1005];

int main(){
    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (vis[x] != 1) {
            q.push(x);
            vis[x] = 1;
            ans++;
        }
        if (q.size() > m) {
            vis[q.front()] = 0;
            q.pop();
        }
    }
    cout << ans << endl;
    return 0;
}