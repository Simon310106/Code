#include <bits/stdc++.h>
using namespace std;

struct node {
    int a, b;
}cow[20];
int n, pos[20];
bool vis[20];
int s = 1e9;

void dfs(int x, int c) {
    if (x > n) {
        s = min(s, c);
        return;
    }
    if (c >= s) {
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            continue;
        }
        vis[i] = true;
        pos[x] = i;
        if (x == 1) {
            dfs(x + 1, 1);
        }
        else {
            dfs(x + 1, c + max(cow[pos[x - 1]].b, cow[i].a) + 1);
        }
        pos[x] = 0;
        vis[i] = 0;
    }
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cow[i].a;
    }
    for (int i = 1; i <= n; i++) {
        cin >> cow[i].b;
    }
    dfs(1, 1);
    cout << s << endl;
    return 0;
}