#include <bits/stdc++.h>
using namespace std;

int n, l, r, cnt;
int a[50];

void dfs(int x, int sum) {
    if (sum > r) return;
    if (x == n) {
        if (sum >= l && sum <= r) {
            cnt++;
        }
        return;
    }
    dfs(x + 1, sum + a[x + 1]);
    dfs(x + 1, sum);
}

int main(){
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    dfs(0, 0);
    cout << cnt << endl;
    return 0;
}