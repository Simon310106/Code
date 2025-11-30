#include <bits/stdc++.h>
using namespace std;

queue <int> s;
bool vis[1005];
int ans;

int main(){
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (vis[x] != 1) {
            s.push(x);
            vis[x] = 1;
            ans++;
        }
        if (s.size() > m) {
            vis[s.front()] = 0;
            s.pop();
        }
    }
    cout << ans;
    return 0;
}