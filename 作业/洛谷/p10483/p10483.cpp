#include <bits/stdc++.h>
using namespace std;

int n, w, ans = 0x3f3f3f3f;
int c[20], car[20];

void dfs(int x, int l) {
    if (l >= ans) {
        return;
    }
    if (x >= n + 1) {
        ans = l;
        return;
    }
    for (int i = 1; i <= l; i++) {
        if (car[i] + c[x] <= w) {
            car[i] += c[x];
            dfs(x + 1, l);
            car[i] -= c[x];
        }
    }
    car[l + 1] += c[x];
    dfs(x + 1, l + 1);
    car[l + 1] = 0;
}

int main(){
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    sort(c + 1, c + n + 1, greater<int>());
    dfs(1, 1);
    cout << ans;

    return 0;
}