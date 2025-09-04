#include <bits/stdc++.h>
using namespace std;

int n, a, b, k[205];
int ans[205];

void dfs(int cnt, int step) {
    ans[cnt] = step;
    int down = cnt - k[cnt];
    if (down >= 1 && step + 1 < ans[down]) {
        dfs(down, step + 1);
    }
    int up = cnt + k[cnt];
    if (up <= n && step + 1 < ans[up]) {
        dfs(up, step + 1);
    }
    return;
}

int main(){
    memset(ans, 0x3f, sizeof(ans));
	cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    dfs(a, 0);
    cout << (ans[b] == 0x3f3f3f3f ? -1 : ans[b]);
	return 0;
}

