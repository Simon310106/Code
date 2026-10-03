#include <bits/stdc++.h>
using namespace std;

struct node {
    int b, e, t;
}trees[5005];

bool vis[30005];
int n, h, ans;

bool cmp(node x, node y) {
    return x.e < y.e;
}

int main(){
    cin >> n >> h;
    for (int i = 1; i <= h; i++) {
        cin >> trees[i].b >> trees[i].e >> trees[i].t;
    }
    sort(trees + 1, trees + h + 1, cmp);
    for (int i = 1; i <= h; i++) {
        int cur = 0;
        for (int j = trees[i].e; j >= trees[i].b; j--) {
            if (vis[j]) {
                cur++;
            }
        }
        if (cur >= trees[i].t) {
            continue;
        }
        for (int j = trees[i].e; j >= trees[i].b; j--) {
            if (!vis[j]) {
                vis[j] = 1;
                cur++;
                ans++;
                if (cur == trees[i].t) {
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}