#include <bits/stdc++.h>
using namespace std;

string a, b;
int cnt[105];

int dfs(int x, int y, int l, int r) {
    int t = 0;
    if (x > y || l > r) {
        t = 0;
    }
    else if (x == y || l == r) {
        t = 1;
    }
    else {
        int i = b.find(a[x]);
        t += dfs(x + 1, x + i - l, l, i - 1);
        t += dfs(x + i - l + 1, y, i + 1, r);
    }
    cnt[a[x]] = t;
    return t;
}

int main(){
    cin >> a >> b;
    int n = a.size();
    dfs(0, n - 1, 0, n - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < cnt[a[i]]; j++) {
            cout << a[i];
        }
        cout << endl;
    }
    return 0;
}